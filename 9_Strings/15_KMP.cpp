#include<bits/stdc++.h>
using namespace std;

void fillLPS(string str, int lps[]){
    int n=str.length(),len=0;
    lps[0]=0;
    int i=1;
    while(i<n){
        if(str[i]==str[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len==0){
                lps[i]=0;
                i++;
            }
            else{
                len=lps[len-1];
            }
        }
    }
}

void KMP(string pat,string txt){
    int N=txt.length();
    int M=pat.length();
    int lps[M];
    fillLPS(pat,lps);
    // print lps arr.
    for(int i=0;i<M;i++){
        cout << lps[i] << " ";
    }
    cout << endl;
    int i=0,j=0;
    while(i<=N){
        if(pat[j]==txt[i]){ i++; j++; } // if char's match inc. both i and j
        if(j==M){      // if pat. is found
            cout << i-j << " "; // print its 1st ind.
            j = lps[j-1];       // update j to lps[j-1]
        }
        else if(i<N && pat[j] != txt[i]){
            if(j==0){ i++; }    // if j==0 =) even 1st char don't match
            else{ j = lps[j-1]; } // else update j=lps[j-1] as it will tell us next ind.
        }                         // in the pat. with which we can get a pot. match
    }
}

int main(){
    string txt="ababcababaad",pat="ababa";
    KMP(pat,txt);
    return 0;
}