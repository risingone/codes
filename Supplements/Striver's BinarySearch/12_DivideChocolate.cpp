// Leetcode 1231
#include<bits/stdc++.h> 
using namespace std;

bool canGetMoreThanKSubarrays(int arr[],int n,int limit,int k){
    int cnt=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum>=limit){
            cnt++;
            sum=0;
        }
    }
    // as we will also get k sweetness chocolate 
    return cnt>=k+1;
}

int findMaxChocolates(int arr[],int n,int k){
    int low= *min_element(arr,arr+n),high=0;
    for(int i=0;i<n;i++) high += arr[i];
    int ans=1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(canGetMoreThanKSubarrays(arr,n,mid,k)){
            ans=mid;
            low=mid+1;
        } else{
            high=mid-1;
        }
    }
    // cout << ": " << low << " " << high  << " " << ans << endl;
    return ans;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    // int arr[] = {5,6,7,8,9,1,2,3,4}; k=8 , ans=1
    int k=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << findMaxChocolates(arr,n,k) << endl;
    return 0;
}