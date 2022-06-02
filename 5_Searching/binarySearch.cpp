/*To search an element in O(log n) using binary search
Note: Array must be sorted in order to apply binary search*/
#include<bits/stdc++.h>
using namespace std;
int bSearch(int arr[],int n,int x){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]>x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}
int recbSearch(int arr[],int low,int high,int &x){
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(arr[mid]==x) return mid;
    else if(arr[mid]>x){
        return recbSearch(arr,low,mid-1,x);
    }
    else{
        return recbSearch(arr,mid+1,high,x);
    }
}
int main(){
    int A[]={10,20,30,40,50,60};
    int n = sizeof(A)/sizeof(A[0]);
    int x=60;
    cout << bSearch(A,n,x) << endl;
    cout << recbSearch(A,0,n-1,x) << endl;
    return 0;
}