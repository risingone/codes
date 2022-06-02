#include<bits/stdc++.h>
using namespace std;
// Leetcode 1283

int findSumAfterDiv(int arr[],int &n,int &div){
    int sum=0;
    for(int i=0;i<n;i++){
        sum += (arr[i]/div);
        // for geting ceil as stated in Q
        if(arr[i]%div !=  0){
            sum += 1;
        }
    }
    return sum;
}

int findMinDivisor(int arr[],int n,int thres){
    int low=1,high = *max_element(arr,arr+n);
    int ans=high;
    while(low<=high){
        int mid = low + (high-low)/2;
        // mid gives <= thres but we want to find more smaller divisor,
        // hence search on left
        if(findSumAfterDiv(arr,n,mid) <= thres){
            ans=mid;
            high=mid-1;
        } else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {1,2,5,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int threshold=6;
    cout << findMinDivisor(arr,n,threshold) << endl; // 5
    return 0;
}