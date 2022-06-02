#include<bits/stdc++.h>
using namespace std;
// M-1: Using Binary Search 
int ub(int arr[],int &n, int &x){
    int low=0,high=n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]<=x){
            low=mid+1;
        } else{
            high=mid-1;
        }
    }
    return low;
}

// M-2: Using STL
int ub2(int arr[],int &n, int &x){
    return upper_bound(arr,arr+n,x)-arr;
}

int main(){
    int arr[] = {1,3,4,6,6,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=6; // 7
    int ind1 = ub(arr,n,x);
    cout << "At index: " <<ind1 << " -> " << arr[ind1] << endl;
    int ind2 = ub2(arr,n,x);
    cout << "At index: " <<ind2 << " -> " << arr[ind2] << endl;
    return 0;
}