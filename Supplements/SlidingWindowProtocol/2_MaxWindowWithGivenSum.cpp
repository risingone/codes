#include<bits/stdc++.h>
using namespace std;

int calSize(vector<int> &arr,int &sum){
    unordered_map<int,int> ump;
    int curr=0,sz=0;
    for(int i=0;i<arr.size();i++){
        curr += arr[i];
        if(curr==sum) sz=i+1;
        if(ump.find(curr-sum)!=ump.end()){
            sz = max(sz,i-ump[curr-sum]);
        }
        ump[curr]=i;
    }
    return sz;
}

// Type 2: Here we have to find window size
// Largest window with given sum, similarly we can do it for min window
int main(){
    int sum=5;
    vector<int> arr = {3,2,4,5,1,1,1,1,1,3,3};
    cout << calSize(arr,sum) << endl;
    return 0;
}