#include<bits/stdc++.h>
using namespace std;

// M-1
int lb(int arr[],int &n,int &x){
    int low=0,high=n-1;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(arr[mid]< x){
            low=mid+1;
        } else{
            high=mid-1;
        }
    }
    return low; // as low gives index of element
}

// M-2: using STL
int lb2(int arr[],int &n,int &x){
    int l = lower_bound(arr,arr+n,x) - arr; // as lower bound gives iterater to address so we - base address
    return l;
}

int main(){
    int arr[]={1,3,5,7,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int  x=8; // 9
    // M-1
    int ind1 = lb(arr,n,x);
    cout << "At index: " <<ind1 << " -> " << arr[ind1] << endl;
    // M-2
    int ind2 = lb2(arr,n,x);
    cout << "At index: " <<ind2 << " -> " << arr[ind2] << endl;
    return 0;
}