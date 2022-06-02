#include<bits/stdc++.h>
using namespace std;

// naive: O(n^2) 
// outer for loop(for distance) from 1->n
// inner for loop for checking

bool canPlaceCows(int arr[],int n,int cows,int dist){
    int cnt=1,cord=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-cord >= dist){
            cnt++;
            cord=arr[i];
        }
        if(cnt==cows) return true;
    }
    return false;
}

// TC : O(nlogn)
int findMinCows(int arr[],int n,int cows){
    int low=1,high=arr[n-1]-arr[0];
    int res=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canPlaceCows(arr,n,cows,mid)){
            res=mid;
            low=mid+1;
        } else{
            high=mid-1;
        }
    }
    return res;
}

int main(){
    int arr[] = {1,2,4,8,9};
    int cows=3; // 2....n
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    cout << findMinCows(arr,n,cows) << endl;
    return 0;
}