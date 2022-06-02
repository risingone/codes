#include<bits/stdc++.h>
using namespace std;

void patSearchDist(string &txt,string &pat){
    int n= txt.length(),m=pat.length();
    for(int i=0;i<=n-m; ){
        int j=0;
        for(j=0;j<m;j++){
            if(pat[j] != txt[i+j]) break;
        }
        if(j==m){  // if get pat. print starting ind.
            cout << i << " ";
        }
        if(j==0) i++; // if first ele. of both are dist
        else{
            i += j; // else inc by j, as ele. in pat are distinct
        }
    }
}

int main(){
    string txt = "ABCABCDABCD";
    string pat = "ABCD";
    patSearchDist(txt,pat);
    return 0;
}