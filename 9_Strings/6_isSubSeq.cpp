/*Check if a given string is Subsequence of Other e.g "ABCD" and "AD"*/
#include<bits/stdc++.h>
using namespace std;

// recursive approach
bool isSubSeqRec(string &s1, string &s2,int n,int m){
    if(m==0) return true;
    if(n==0) return false;
    if(s1[n-1]==s2[m-1]){
        return isSubSeqRec(s1,s2,n-1,m-1);
    }
    else{
        return isSubSeqRec(s1,s2,n-1,m);
    }
}

// efficient approach
bool isSubSeq(string &s1,string &s2,int n,int m){
    int j=0;
    for(int i=0;i<n && j<m;i++){
        if(s1[i]==s2[j]) j++;
    }
    return j==m; // return true if j reaches to end
}

int main(){
    string s1="ITCOUNTS";
    string s2="INS";
    cout << isSubSeqRec(s1,s2,s1.length(),s2.length()) << endl;
    cout << isSubSeq(s1,s2,s1.length(),s2.length()) << endl;
    return 0;
}