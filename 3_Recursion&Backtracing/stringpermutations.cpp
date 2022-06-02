/*in it we will try to find all the  different possible permutations of a string*/
#include<bits/stdc++.h>
using namespace std;
unordered_set<string> check; // to check if string is already printed
string interchangeChar(string s,int a,int b){  //this function swaps first character of string with rest
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
    return s;
}
void permutations(string s,int l,int r){
    if(l==r){                                   
        if(check.find(s)!=check.end()) return;
        check.insert(s);
        cout << s << " ";
        return;
    }
    for(int i=0;i<r;i++){
        s=interchangeChar(s,l,i);
        permutations(s,l+1,r);
        s=interchangeChar(s,l,i);
    }
}
int main(){
    permutations("abc",0,3);
    return 0;
}