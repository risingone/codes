#include<bits/stdc++.h>
using namespace std;

// find minm in rotated sorted array with distinct elements
int findMin(int arr[],int &n){
    int low=0, high=n-1;
    while(low<high){ // we use low<high here to keep low on result
        int mid=low+(high-low)/2;
        if(arr[mid]<arr[high]){
            high=mid; // as it is possible that it is the minm
        } else{
            low=mid+1;
        }
    }
    return arr[low];
}

// find minm in rotated sorted array containing duplicates
// e.g: 1 0 0 1 1 1 1
int findMin2(int arr2[],int &sz){
    int low=0,high=sz-1;
    while(low<high){
        int mid = low + (high-low)/2;
        if(arr2[mid]<arr2[high]){
            high=mid;
        } else if(arr2[mid]>arr2[high]){
            low=mid+1;
        } else{ // in case of equal, as answer might be present in b/w 
            high--;
        }
    }
    return arr2[low];
}

// Search in Rotated Sorted array(distinct elements)
// e.g = {7,8,9,1,2,4,5,6}, in it we know one part of array is definitely sorted
int findEl(int arr[],int &n, int &x){
    int low=0,high=n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == x) return mid;
        if(arr[low] <= arr[mid]){ // left half is sorted
            if(x >=arr[low] && x<arr[mid]){ // and x is present in it
                high = mid-1;
            } else{
                low=mid+1;
            }
        } else{ // right half is sorted
            if(x>arr[mid] && x<=arr[high]){ // and x is present in it
                low = mid+1;
            } else{
                high = mid-1;
            }
        }
    }
    return -1; // if not present
}


int main(){
    int arr[] = {7,8,9,1,2,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Find minimum in rotated sorted(distinct elements): ";
    cout << findMin(arr,n) << endl;
    int x=8;
    cout << "Search x in rotated sorted(distinct elements): ";
    cout << findEl(arr,n,x) << endl; // index of x
    int arr2[] = {1,1,1,0,0,1}; 
    int sz = sizeof(arr2)/sizeof(arr2[0]);
    cout << "Find minimum in rotated sorted(duplicate elements): ";
    cout << findMin2(arr2,sz) << endl; 
    return 0;
}