#include<bits/stdc++.h>
using namespace std;

string printNumber(string s, int n) 
{
    //code here
    char arr[]="22233344455566677778889999";
    string res="";
    for(int i=0;i<n;i++){
        if(s[i]>='a'&&s[i]<='z'){
            res += arr[s[i]-'a'];
        }
        else if(s[i]>='A'&&s[i]<='Z'){
            res += arr[s[i]-'A'];
        }
    }
    return res;
}

int main(){
    string s="ABCgeeks";
    int n=s.length();
    cout << printNumber(s,n) << endl;
    return 0;
}