#include<bits/stdc++.h>
using namespace std;
const int CHAR = 256;

// naive approach O(n logn)
bool areAnagram(string &s1, string &s2){
    if(s1.length() != s2.length()) return false; // first check the length
    sort(s1.begin(),s1.end());  // then sort
    sort(s2.begin(),s2.end());
    return (s1==s2);            // then compare
}

// efficient approach
bool checkAnagram(string &s1,string &s2){
    if(s1.length()!=s2.length()) return false;
    int count[CHAR] = {0};
    for(int i=0;i<s1.length();i++){
        count[s1[i]]++;    // for 1 str inc. freq for char
        count[s2[i]]--;    // and dec. for other str
    }
    for(int i=0;i<CHAR;i++){ // check if freq. for all char. are 0
        if(count[i]!=0) return false;
    }
    return true;
}

int main(){
    string s1="listen",s2="silent";
    cout << areAnagram(s1,s2) << endl;
    cout << checkAnagram(s1,s2) << endl;
    return 0;
}