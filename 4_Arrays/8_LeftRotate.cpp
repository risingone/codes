/*To left rotate an Array by 1 or by d times*/
#include<bits/stdc++.h>
using namespace std;
void lRotateOne(int arr[],int n){
    int temp=arr[0]; // store 1 array element
    for(int i=1;i<n;i++){ // shift entire array left by 1
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp; // load 1 array element at end
}
//M-1
void leftRotate(int arr[],int n,int d){ // left rotate by d times naive approach Time: O(n*d) Space; O(1)
    for(int i=0;i<d;i++){ // repeat rotate left by 1 d times
        lRotateOne(arr,n);
    }
}
//M-2
void leftRotate2(int arr[],int n,int d){ //Time: O(n) Space: O(d)
    int temp[d];
    for(int i=0;i<d;i++){ // copy first d elements in temporary array
        temp[i]=arr[i];
    }
    for(int i=d;i<n;i++){ // swap rest n-d elements
        arr[i-d]=arr[i];
    }
    for(int i=0;i<d;i++){ // load those d elements at the end
        arr[n-d+i]=temp[i];
    }
}
//M-3: Reversal Algorithm
void reverse(int arr[],int low,int high){
    while(low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}
void leftRotate3(int arr[], int n, int d){ // 1 2 3 4 5   -> 2
    reverse(arr,0,d-1);                    // 2 1 3 4 5
    reverse(arr,d,n-1);                    // 2 1 5 4 3
    reverse(arr,0,n-1);                    // 3 4 5 1 2
}
int main(){
    int A[]={1,2,3,4,5};
    // lRotateOne(A,5);
    // leftRotate(A,5,2);
    // leftRotate2(A,5,3);
    leftRotate3(A,5,2);
    for(int i=0;i<5;i++){
        cout << A[i] << " ";
    }
    return 0;
}