#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^') return true;
    return false;
}

int precedence(char c){
    if(c=='^') return 3;
    else if(c=='*'||c=='/') return 2;
    else if(c=='+'||c=='-') return 1;
    return -1;
}

string infixToPrefix(string s){
    int n=s.length();
    stack<char> stk;
    string res;
    // we traverse from R->L
    for(int i=n-1;i>=0;i--){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            res += s[i];
        }
        else if(s[i]==')'){
            stk.push(s[i]);
        }
        else if(s[i]=='('){
            while(!stk.empty()&&stk.top()!=')'){
                res+=stk.top();
                stk.pop();
            }
            stk.pop(); // remove ')'
        }
        else if(isOperator(s[i])){
            if(stk.empty()){
                stk.push(s[i]);
            }
            else{
                // if precedence is greater
                if(precedence(s[i])>precedence(stk.top())){
                    stk.push(s[i]);
                }
                else{
                    // while precedence of stack top is lower pop()
                    while(!stk.empty()&&(precedence(s[i])<precedence(stk.top()))){
                        res += stk.top();
                        stk.pop();
                    }
                    // in case of '^' pop() on = precedence, to maintain associativity
                    while(!stk.empty()&&(precedence(s[i])==precedence(stk.top()))&&s[i]=='^'){
                        res += stk.top();
                        stk.pop();
                    }
                    // push s[i], it will be common for both case mentioned above
                    // and also maintain associativity for = precedence in case of '+','_' & '*','/'
                    stk.push(s[i]);
                }
            }
        }
    }
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    string s="a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPrefix(s) << endl; //-+a*b^-^cde+f*ghi
    return 0;
}