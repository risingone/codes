/* Find minm length Subarray with sym >= target*/
#include<bits/stdc++.h>
using namespace std;

bool windowSum(int arr[],int &n,int target,int k){ // k length window
    int sum=0;
    for(int i=0;i<k;i++){ // sum of elements upto k-1 index
        sum += arr[i];
    }
    int maxi = sum;
    int l=0,r=k;
    while(r != n) {
        sum -= arr[l];
        l++;
        sum+= arr[r];
        r++;
        maxi = max(maxi, sum);
    }
    return maxi >= target;
}

// O(NlogN)
int findMinLength(int arr[],int &n,int target){
    int low=1,high=n; // length of possible subarray
    bool ansPossible=false;
    while(low<high){
        int mid = low + (high-low)/2;
        if(windowSum(arr,n,target,mid)==true){
            ansPossible = true;
            high=mid;
        } else{
            low=mid+1;
        }
    }
    return (ansPossible)?low:-1;
}

int main(){
    int arr[] = {2,3,1,2,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=7;
    // cout << n << " " << target << endl;
    cout << findMinLength(arr,n,target) << endl;
    return 0;
}