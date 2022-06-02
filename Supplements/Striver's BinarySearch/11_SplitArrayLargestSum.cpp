//LC: 410
#include<bits/stdc++.h>
using namespace std;

int numberOfSubarraysByKeepingLimit(int arr[],int &n,int &limit,int &m){
    int cnt = 1,sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>limit) return false;
        if(sum+arr[i] > limit){
            cnt++;
            sum=arr[i];
        } else{
            sum += arr[i];
        }
    }
    return cnt <= m;
}

int minMaxSumSubarray(int arr[],int &n,int &m){
    int low=*max_element(arr,arr+n);
    int high=0;
    for(int i=0;i<n;i++) high += arr[i];
    int ans=high;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(numberOfSubarraysByKeepingLimit(arr,n,mid,m)==false){
            low=mid+1;
        } else{
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {7,2,5,10,8};
    int m=2;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << minMaxSumSubarray(arr,n,m) << endl;
    return 0;
}