/*To insert an element in an Array which is not full*/
#include<bits/stdc++.h>
using namespace std;
int insert(int arr[], int n, int x, int cap, int pos){
    if(n==cap) return n;
    int idx = pos-1;
    for(int i=n-1;i>=idx;i--){
        arr[i+1] = arr[i];
    }
    arr[idx]=x;
    return n+1;
}
int main(){
    int A[6];
    A[0]=5;
    A[1]=3;
    A[2]=7;
    A[3]=10;
    A[4]=20; //  5 3 7 10 20
    int n = insert(A,5,8,6,2); // pos=6,idx=5,x=8
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    return 0;
}