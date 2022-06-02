#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>& a,pair<int,int>& b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}

vector<int> sortByFreq(int arr[],int n){
    //Your code here
    vector<int> res;
    unordered_map<int,int> ump; // to store dist. ele. with their freq.
    for(int i=0;i<n;i++){
        ump[arr[i]]++;
    }
    vector<pair<int,int>> vec;
    for(auto& it: ump){ // now copy pairs from map to a vec. of pairs
        vec.push_back(it);
    }
    sort(vec.begin(),vec.end(),cmp); // sort the vec
    for(auto& it:vec){               // place val. in desired fashion in res. arr
        int val=it.first,fq=it.second;
        for(int j=0;j<fq;j++){
            res.push_back(val);
        }
    }
    return res;
}

int main(){
    int n=5;
    int A[] = {5,5,4,6,4};
    vector<int> ans=sortByFreq(A,n);
    for(auto& it : ans){
        cout << it << " ";
    }
    return 0;
}