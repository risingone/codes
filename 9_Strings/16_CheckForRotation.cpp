#include<bits/stdc++.h>
using namespace std;

bool areRotations(string &s1,string &s2){ 
    if(s1.length()!=s2.length()) return false;
    return ((s1+s1).find(s2) != string::npos);  // if string is not found, find func. return string::npos
}

int main(){
    string s1="ABCD",s2="CDAB"; // we can modify the Q to say that we have to
    cout << areRotations(s1,s2);// search CDAB in ABCDABCD => s1+s1
    return 0;
}