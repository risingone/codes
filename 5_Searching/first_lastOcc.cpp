/*Find the index of first and last occurences of a number in an array
we will do it using binary search as we now for linear it is easy and will take O(n) time*/
#include<bits/stdc++.h>
using namespace std;
int recfirstOcc(int arr[], int low, int high, int &x){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(x>arr[mid]){
        return recfirstOcc(arr,mid+1,high,x);
    }
    else if(x<arr[mid]){
        return recfirstOcc(arr,low,mid-1,x);
    }
    else{
        if(mid==0||arr[mid]!=arr[mid-1]){
            return mid;
        }
        else{
            return recfirstOcc(arr,low,mid-1,x);
        }
    }
}
int firstOcc(int arr[],int n,int &x){
    int low=0,high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>x){
            high = mid-1;
        }
        else if(arr[mid]<x){
            low = mid+1;
        }
        else{
            if(mid==0 || arr[mid-1]!=arr[mid]){
                return mid;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}
int reclastOcc(int arr[],int low,int high,int &x,int &n){
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(arr[mid]>x){
        return reclastOcc(arr,low,mid-1,x,n);
    }
    else if(arr[mid]<x){
        return reclastOcc(arr,mid+1,high,x,n);
    }
    else{
        if(mid==n-1||arr[mid]!=arr[mid+1]){
            return mid;
        }
        return reclastOcc(arr,mid+1,high,x,n);
    }
}
int lastOcc(int arr[],int n,int x){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<x) low=mid+1;
        else if(arr[mid]>x) high=mid-1;
        else{
            if(mid==n-1||arr[mid]!=arr[mid+1]){
                return mid;
            }
            else{
                low=mid+1;
            }
        }
    }
    return -1;
}
int main(){
    int A[]={1,10,10,10,20,20,40};
    int n=sizeof(A)/sizeof(A[0]);
    int x=10;
    cout << recfirstOcc(A,0,n-1,x) << endl;
    cout << firstOcc(A,n,x) << endl;
    cout << reclastOcc(A,0,n-1,x,n) << endl;
    cout << lastOcc(A,n,x) << endl;
    return 0;
}