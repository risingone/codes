#include<bits/stdc++.h>
using namespace std;
// Type 1: Sliding window where size is given
// get sum of all k size windows, Naive approach will be O(n^2) with 2 loops
// sliding window will only take 1 traversal O(n) 
vector<int> getKSum(vector<int> &arr,int &k){
    vector<int> res;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if((i-k)>=0) sum -= arr[i-k];
        if(i>=2) res.push_back(sum);
    }
    return res;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int k=3;
    vector<int> ans = getKSum(arr,k);
    for(auto &it: ans){
        cout << it << " ";
    }
    return 0;
}