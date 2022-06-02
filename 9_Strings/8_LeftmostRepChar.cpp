#include<bits/stdc++.h>
using namespace std;
const int CHAR=256;

// naive approach O(n^2)
int leftMost(string &str){
    for(int i=0;i<str.length();i++){
        for(int j=i+1;j<str.length();j++){
            if(str[i]==str[j]) return i;
        }
    }
    return -1;
}

// efficient approach
int leftMost1(string &str){
    int count[CHAR] = {0};
    for(int i=0;i<str.length();i++){
        count[str[i]]++;
    }
    for(int i=0;i<str.length();i++){
        if(count[str[i]]>1) return i;
    }
    return -1;
}

// efficient approach
int leftMost2(string &str){
    int fIndex[CHAR];
    fill(fIndex, fIndex+CHAR, -1);
    int res=INT_MAX;
    for(int i=0;i<str.length();i++){
        int fi=fIndex[str[i]];
        if(fi==-1) fIndex[str[i]]=i; // if ele. occurs 1 time store its index
        else
            res = min(res, fi); // else update res
    }
    return (res==INT_MAX)? -1: res;
}

// most efficient approach
int leftMost3(string &str){
    int res=-1;
    bool visited[CHAR];
    fill(visited, visited+CHAR,false);
    for(int i=str.length()-1;i>=0;i--){
        if(visited[str[i]]) res=i;
        else
            visited[str[i]] = true;
    }
    return res;
}

int main(){
    string str = "yashsharma";
    cout << leftMost(str) << endl;
    cout << leftMost1(str) << endl;
    cout << leftMost2(str) << endl;
    cout << leftMost3(str) << endl;
    return 0;
}