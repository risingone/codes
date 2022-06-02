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
    else return -1;
}

string InfixToPostfix(string infix){
    stack<char> s;
    string postfix;
    for(int i=0;i<infix.length();i++){
        // if operand, add to string
        if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z')){
            postfix += infix[i];
        }
        else if(infix[i]=='('){
            s.push(infix[i]);
        }
        else if(infix[i]==')'){
            while((!s.empty())&&(s.top()!='(')){
                postfix += s.top();
                s.pop();
            }
            s.pop(); // to remove '('
        }
        // if operator
        else if(isOperator(infix[i])){
            if(s.empty()){
                s.push(infix[i]);
            }
            else{
                if(precedence(infix[i])>precedence(s.top())){
                    s.push(infix[i]);
                }
                // associativity R->L
                else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^')){
                    s.push(infix[i]);
                }
                else{
                    while(!s.empty()&&(precedence(infix[i])<=precedence(s.top()))){
                        postfix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    // add stack ele. if stack is not empty
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}

int main(){
    string infix,postfix;
    cout << "Enter Infix string: "; // "a+b*(c^d-e)^(f+g*h)-i"
    cin >> infix;
    postfix=InfixToPostfix(infix);  // abcd^e-fgh*+^*+i-
    cout << postfix << endl;
    return 0;
}