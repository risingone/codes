#include<bits/stdc++.h>
using namespace std;

// naive approach
bool isPal(string &str){
    string rev=str;
    reverse(rev.begin(),rev.end());
    return rev==str;
}

// efficient approach: using 2ptr
bool isPal1(string &str){
    int begin=0;
    int end=str.length()-1;
    while(begin<end){
        if(str[begin]!=str[end])
            return false;
        begin++;
        end--;
    }
    return true;
}

int main(){
    string str="ABCBA";
    cout << isPal(str) << endl;
    cout << isPal1(str) << endl;
    return 0;
}