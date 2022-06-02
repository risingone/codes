/* Find a peak element(not smaller than neighbours) in a given array*/
#include<bits/stdc++.h>
using namespace std;
// M-1 naive approach
int getPeak(int arr[],int n){
    if(n==1) return arr[0];
    if(arr[0]>=arr[1]) return arr[0];
    if(arr[n-1]>=arr[n-2]) return arr[n-1];
    for(int i=1;i<n-1;i++){
        if(arr[i]>=arr[i-1] && arr[i] >= arr[i+1]) return arr[i];
    }
    return -1;
}
// M-2 efficient solution
int getPeak2(int arr[], int n){
    int low=0, high=n-1;
    while(low <= high){ 
        int mid = (low+high)/2;
        if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid])){
            return mid;//returns index
        }
        if(mid>0 && arr[mid-1]>=arr[mid]){
            high =mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}
int main(){
    int A[]={5,10,20,30,15,7};
    int n=sizeof(A)/sizeof(A[0]);
    cout << getPeak(A,n) << endl;
    cout << getPeak2(A,n) << endl;
    return 0;
}