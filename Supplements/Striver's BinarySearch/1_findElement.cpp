#include<bits/stdc++.h>
using namespace std;

// iterative
int findEl(int arr[],int &n,int &x){
    int low=0,high=n-1;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(arr[mid]==x){
            return mid;
        } else if(x>arr[mid]){
            low=mid+1;
        } else{
            high=mid-1;
        }
    }
    return -1;
}

// recursive
int findElRecur(int arr[],int low,int high,int &x){
    if(low>high) return -1;
    int mid=low+(high-low)/2;
    if(arr[mid]==x) return mid;
    else if(arr[mid]<x) return findElRecur(arr,mid+1,high,x);
    else return findElRecur(arr,low,mid-1,x);
}

int main(){
    int n=8,x=11;
    int arr[] = {1,2,3,4,6,9,11,14};
    cout << findEl(arr,n,x) << endl; // return 11's index
    cout << findElRecur(arr,0,n,x) << endl;
    return 0;
}