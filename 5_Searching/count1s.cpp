/*To count 1s in a sorted binary array*/
#include<bits/stdc++.h>
using namespace std;
int countOnes(bool arr[],int n){
    int low=0,high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]==0) low=mid+1;
        else{
            if(mid==0||arr[mid-1]!=arr[mid]){
                return (n-mid);
            }
            else{
                high = mid-1;
            }
        }
    }
    return 0;
}
int main(){
    bool A[] ={0,0,0,1,1,1,1};
    int n = sizeof(A)/sizeof(A[0]);
    cout << countOnes(A,n) << endl;
    return 0;
}