#include<bits/stdc++.h>
using namespace std;


// M-1: Using Recursion
// TC: O(n*2^n) Aux SC: O(n)
void getSubsequences(int ind,vector<int> &ds,int arr[],int &n){
    if(ind==n){
        for(auto &it: ds){
            cout << it << " ";
        }
        if(ds.size()==0){
            cout << "{}" << " ";
        }
        cout << endl;
        return;
    }
    // we can also place line 21 here to take not pick condition before
    // take or pick particular index element into the subsequence
    ds.push_back(arr[ind]);
    getSubsequences(ind+1,ds,arr,n);
    ds.pop_back();
    // not pick or not take condition, this element is not added to your subsequence
    getSubsequences(ind+1,ds,arr,n);
}

// M-2: Using Power Set
// TC: O(n* 2^n)
void getSubsequences2(int arr[],int &n){
    for(int num=0;num<pow(2,n);num++){
        vector<int> ds;
        for(int i=0;i<n;i++){
            if(num&(1<<i)){
                ds.push_back(arr[i]);
            }
        }
        for(auto &it: ds){
            cout << it << " ";
        }
        if(ds.size()==0){
            cout << "{}" << " ";
        }
        cout << endl;
    }
}

int main(){
    int arr[] = {3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ds;
    getSubsequences(0,ds,arr,n);
    getSubsequences2(arr,n);
    return 0;
}