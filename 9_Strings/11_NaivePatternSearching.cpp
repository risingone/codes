#include<bits/stdc++.h>
using namespace std;

void patSearching(string &txt, string &pat){
    int m= pat.length();
    int n= txt.length();
    for(int i=0;i<=n-m;i++){ // traverse txt upto n-m ind as pat. can't lie beyond it
        int j;
        for(j=0;j<m;j++){  // exec. till txt. matches pat.
            if(pat[j]!=txt[i+j]) break;
        }
        if(j==m){  // j=pat. length we found the pat.
            cout << i << " ";
        }
    }
}

int main(){
    string txt = "ABCGHABCDJHK";
    string pat = "ABCD";
    patSearching(txt,pat);
    return 0;
}