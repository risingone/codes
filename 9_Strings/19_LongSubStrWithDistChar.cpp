#include<bits/stdc++.h>
using namespace std;

bool areDistinct(string str,int i,int j){
    vector<bool> visited(256);
    for(int k=i; k<=j; k++){
        if(visited[str[k]]==true){
            return false;
        }
        visited[str[k]]=true;
    }
    return true;
}
// naive solution O(n^3)
int longestDistinct(string str){
    int n=str.length(),res=0;
    for(int i=0;i<n;i++){       // traverse all substrings
        for(int j=i;j<n;j++){
            if(areDistinct(str,i,j)) // if all char. in string are diff.
                res = max(res, j-i+1); // update res
        }
    }
    return res;
}

// Better Solution: O(n^2)
int longestDistinct1(string str){
    int n=str.size(),res=0;
    for(int i=0;i<n;i++){ // traverse str
        vector<bool> visited(256); // for each ind.
        for(int j=i;j<n;j++){      // check max dist. char's string length
            if(visited[str[j]]==true) break;
            else{
                res = max(res,j-i+1); // update res. acc.
                visited[str[j]]=true;
            }
        }
    }
    return res;
}

// Efficient Solution O(n)
int longestDist(string str){
    int n=str.length(),res=0;
    vector<int> prev(256,-1); // to store ind of occ. char's
    int i=0;
    for(int j=0;j<n;j++){     // traverse string
        i=max(i,prev[str[j]]+1); // i will be i or prev. occ. ind. of str[i]+1;
        int maxEnd = j-i+1; // modify max ind for every traversal
        res=max(res,maxEnd); // update res
        prev[str[j]]=j;  //store ind. of occ. char in prev vector
    }
    return res;
}

int main(){
    string str="abacdbab";
    cout << longestDistinct(str) << endl;
    cout << longestDistinct1(str) << endl;
    cout << longestDist(str) << endl;
    return 0;
}