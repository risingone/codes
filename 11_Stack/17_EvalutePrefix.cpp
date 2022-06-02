#include<bits/stdc++.h>
using namespace std;

int evalPrefix(string s){
    int n=s.length(),op1,op2,res;
    stack<int> stk;
    for(int i=n-1;i>=0;i--){
        if(s[i]>='0'&&s[i]<='9'){
            stk.push(s[i]-'0');
        }
        else{
            op1=stk.top();
            stk.pop();
            op2=stk.top();
            stk.pop();
            switch(s[i]){
                case '+':
                    res = op1+op2;
                    break;
                case '-':
                    res = op1-op2;
                    break;
                case '*':
                    res = op1*op2;
                    break;
                case '/':
                    res = op1/op2;
                    break;
                default:
                    break;
            }
            stk.push(res);
        }
    }
    return stk.top();
}

int main(){
    string s="+*933";
    cout << evalPrefix(s) << endl;
    return 0;
}