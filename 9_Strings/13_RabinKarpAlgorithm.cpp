#include<bits/stdc++.h>
#define d 256
using namespace std;
const int q=101;

void RBSearch(string &pat, string &txt){
    int m=pat.length(),n=txt.length();
    int h=1;
    for(int i=1;i<=m-1;i++){  // to cal (d^(m-1))%q
        h = (h*d)%q;
    }
    int p=0,t=0; // to store pat and txt char's sum with length m
    for(int i=0;i<m;i++){
        p = (p*d + pat[i])%q;
        t = (t*d + txt[i])%q;
    }
    for(int i=0; i<=n-m; i++){
        // check for spurious hits
        if(p==t){
            bool flag=true;
            for(int j=0;j<m;j++){
                if(txt[i+j] != pat[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout << i << " ";
            }
        }
        // compute t(i+1) using t(i)
        if(i<n-m){
            t = ((d*(t - txt[i]*h)) + txt[i+m])%q;
            if(t<0) t=t+q;
        }
    } 
}

int main(){
    string txt = "abdabcbabc";
    string pat = "abc";
    RBSearch(pat,txt);
    return 0;
}