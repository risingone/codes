#include<bits/stdc++.h>
using namespace std;

int evaluatePostfix(string S)
    {
        // Your code here
        int op1,op2,res;
        stack<int> stk;
        for(int i=0;i<S.length();i++){
            if(S[i]>='0'&&S[i]<='9'){
                stk.push(S[i]-'0');
            }
            else{
                op1=stk.top();
                stk.pop();
                op2=stk.top();
                stk.pop();
                switch(S[i]){
                    case '+':
                        res = op2 + op1;
                        break;
                    case '-':
                        res = op2 - op1;
                        break;
                    case '*':
                        res = op2 * op1;
                        break;
                    case '/':
                        res = op2 / op1;
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
    string S="123+*8-";
    cout << evaluatePostfix(S) << endl; // -3
    return 0;
}