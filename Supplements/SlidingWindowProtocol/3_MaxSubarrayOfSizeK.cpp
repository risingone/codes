#include<bits/stdc++.h>
using namespace std;
// Type-1

// way-1
int maxSum(vector<int> &arr, int k){
    int sum=0,curr=0;
    for(int i=0;i<arr.size();i++){
        curr+=arr[i];
        if(i>=k) curr -= arr[i-k];
        if(i>=(k-1)) sum = max(sum,curr);
    }
    return sum;
}

// way-2
int maxSum2(vector<int> &arr, int k){
    int sum = 0,mx=0,i=0,j=0;
    while(j<arr.size()){
        sum += arr[j];
        if((j-i+1)<k) j++;
        else if((j-i+1)==k){
            mx = max(sum,mx);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return mx;
}

int main(){
    vector<int> arr = {3,5,1,8,2,9,1};
    int k=3;
    cout << maxSum(arr,k) << endl;
    cout << maxSum2(arr,k) << endl;
    return 0;
}