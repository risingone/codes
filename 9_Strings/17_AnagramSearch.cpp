#include<bits/stdc++.h>
using namespace std;
const int CHAR=256;

bool areAnagram(string &pat,string &txt,int i){
    int count[CHAR]={0};
    for(int j=0;j<pat.length();j++){
        count[pat[j]]++;
        count[txt[i+j]]--;
    }
    for(int j=0;j<CHAR;j++){
        if(count[j]!=0) return false;
    }
    return true;
}
// naive solution
bool isPresent(string &txt,string &pat){
    int n=txt.length();
    int m=pat.length();
    for(int i=0;i<=n-m;i++){ // for each ind we check if txt from i-(i+m-1) ind. 
        if(areAnagram(pat,txt,i)){ // is pattern's anagram or not
            // cout << i << endl; // print ind.
            return true;
        }
    }
    return false;
}

// efficient solution
bool areSame(int CT[CHAR],int CP[CHAR]){
    for(int i=0;i<CHAR;i++){
        if(CT[i]!=CP[i]) return false;
    }
    return true;
}
bool isPresent1(string &txt, string &pat){
    int CT[CHAR]={0},CP[CHAR]={0};
    for(int i=0;i<pat.length();i++){ // fill char. freq. arr for first m(pat. len) char's
        CT[txt[i]]++;
        CP[pat[i]]++;
    }
    for(int i=pat.length();i<=txt.length();i++){ // we use sliding window protocol
        if(areSame(CT,CP))                       // to search pat.
            return true;
        CT[txt[i]]++;
        CT[txt[i-pat.length()]]--;
    }
    return false;
}

int main(){
    string txt="forgeeks",pat="seek";
    cout << isPresent(txt,pat) << endl;
    cout << isPresent1(txt,pat) << endl;
    return 0;
}