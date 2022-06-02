#include<bits/stdc++.h>
using namespace std;
const int CHAR = 256;

// naive sol. O(n^2)
int nonRep(string &str){
    for(int i=0;i<str.length();i++){
        bool flag = false;
        for(int j=0;j<str.length();j++){
            if(i!=j && str[i]==str[j]){
                flag=true;
                break;
            }
        }
        if(!flag){
            return i;
        }
    }
    return -1;
}

// efficient solution
int nonRep1(string &str){
    int count[CHAR] = {0};
    for(int i=0;i<str.length();i++){ // store freq. of each char.
        count[str[i]]++;
    }
    for(int i=0;i<str.length();i++){ // traverse again and return ind. of
        if(count[str[i]]==1) return i; // 1 ele. with freq 1
    }
    return -1;
}

//efficient approach
int nonRep2(string &str){
    int fi[CHAR];
    fill(fi,fi+CHAR,-1);
    for(int i=0;i<str.length();i++){
        if(fi[str[i]]==-1) fi[str[i]]=i;  // on 1 occ. fi stores ind. of char
        else{
            fi[str[i]]=-2;                // on next occ. it stores -2 at char's place
        }
    }
    int res = INT_MAX;
    for(int i=0;i<CHAR;i++){
        if(fi[i]>=0) res=min(res,fi[i]); // update res
    }
    return (res==INT_MAX)?-1:res;
}

int main(){
    string str = "geeksforgeeks";
    cout << nonRep(str) << endl;
    cout << nonRep1(str) << endl;
    cout << nonRep2(str) << endl;
    return 0;
}