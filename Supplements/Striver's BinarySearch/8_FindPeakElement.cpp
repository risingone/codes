// LeetCode 162
/* Element whose immediate left and immediate right are < than it
*/
#include<bits/stdc++.h>
using namespace std;

int findPeak(int arr[], int n){
    int low=0, high=n-1;
    while(low<high){
        int mid = low+(high-low)/2;
        /* As we know if mid element greater than mid+1 th element then surely
           peak element is in left side including mid, as for elements there are 2
           cases they are < mid(which makes mid peak) else keep increasing (it makes 0th elemnent peak)*/
        if(arr[mid]>arr[mid+1]){
            high = mid; // as mid is a possible solution
        } else{
            low = mid+1;
        }
    }
    return arr[low];
}

int main(){
    int arr[] = {1,2,3,4,3,5,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << findPeak(arr,n) << endl;
    return 0;
}