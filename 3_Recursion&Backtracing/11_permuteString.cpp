#include<bits/stdc++.h>
using namespace std;

void permute(string s, int i){
    if(i==s.length()-1){    // when we reach len. - 1
        cout << s << " ";   // we print the string
        return;
    }
    for(int j=i;j<s.length();j++){
        swap(s[i],s[j]); // we swap ith ele with jth 
        permute(s,i+1);  // and find different perm.
        swap(s[i],s[j]); // and swap again to retain org. str.
    }                    // to find ret perm.
}

int main(){
    string s="abcd";
    permute(s,0);
    return 0;
}