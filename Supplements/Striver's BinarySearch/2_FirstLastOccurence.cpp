#include<bits/stdc++.h>
using namespace std;

// first occ. using BS
int firstOccurrence(int arr[],int n, int x){
    int low=0,high=n-1;
    // int ans=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==x){
            // ans = mid;
            high=mid-1;
        } else if(arr[mid]<x){
            low = mid+1;
        } else{
            high = mid-1;
        }
    }
    // return ans;
    // as we know low will point to first occurence at the end
    return low;
}

// last occ. using BS
int lastOccurrence(int arr[],int &n,int &x){
    int low=0,high=n-1;
    while(low<=high){
        int mid=low + (high-low)/2;
        if(arr[mid]==x){
            low=mid+1;
        } else if(x>arr[mid]){
            low=mid+1;
        } else{
            high=mid-1;
        }
    }
    return high;
}

int main()
{
    int n=8,x=4;
    int arr[] = {1,1,4,4,4,4,5,5};
    int first = firstOccurrence(arr,n,x);
    int last = lastOccurrence(arr,n,x);
    cout << "first occured at index: " << first << endl;
    cout << "last occured at index: " << last << endl;
    cout << "no. of occurences of " << x << " are: " << (last-first+1) << endl;
    return 0;
}