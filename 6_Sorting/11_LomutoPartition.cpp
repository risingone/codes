#include <bits/stdc++.h>
using namespace std;
int lPartition(int arr[],int l,int h){
    int pivot = arr[h]; // always last
    int i=l-1;
    for(int j=l;j<=h-1;j++){ // we consider array upto i index consist of elements < pivot
        if(arr[j]<pivot){   // if we encounter an element < pivot
            i++;            // we increment i
            swap(arr[i],arr[j]);// swap the ith and jth elements 
        }
    }
    swap(arr[i+1],arr[h]); // at end we place pivot at its correct position
    return (i+1);
}
int main(){
    int arr[]={10,80,30,90,40,50,70}; // in it  by default pivot is end element
    cout << lPartition(arr,0,6) << endl;
    for(int i=0;i<7;i++){
        cout << arr[i] <<" ";
    }
    return 0;
}