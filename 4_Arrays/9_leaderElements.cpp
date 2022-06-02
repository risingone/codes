/*To print all the leader elements(elements which don't have any element gretar than equal to them on their right) in an array*/
#include<bits/stdc++.h>
using namespace std;
//M1 naive approach
void leaders(int arr[], int n){ 
    for(int i=0;i<n;i++){           // for each element we will check
        bool flag=true;             // if there exist an element greater than that on right side
        for(int j=i+1; j<n; j++){   // we will skip it otherwise we will print it
            if(arr[i] <= arr[j]){
                flag=false;
                break;
            }
        }
        if(flag){
            cout << arr[i] << " ";
        }
    }
}
//M2 it will be O(n) but will print leader elements from right to left,
//we could use a stack to print from left to right
void leaders2(int arr[], int n){
    int curr_ldr = arr[n-1]; //take rightmost element as current leader
    cout << curr_ldr << " "; // print it
    for(int i=n-2;i>=0;i--){ // then traverse towards left
        if(curr_ldr<arr[i]){ // if element we get is > curr leader
            curr_ldr=arr[i]; // update current leader
            cout << curr_ldr << " ";// and print it
        }
    }
}
int main(){
    int A[]={7,10,4,10,6,5,2};
    // leaders(A,7);
    leaders2(A,7);
    return 0;
}