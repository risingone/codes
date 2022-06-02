#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[],int n,int i){ // it will build a maxHeap and bring largest element on left
    int largest=i,left=2*i+1,right=2*i+2;
    if(left<n && arr[left]>arr[largest]) largest = left;
    if(right<n && arr[right]>arr[largest]) largest=right;
    if(largest != i){
        swap(arr[largest], arr[i]);
        maxHeapify(arr,n,largest);
    }
}

void buildHeap(int arr[], int n){
    for(int i=(n-2)/2;i>=0;i--){ // start calling from rightmost elements parent
        maxHeapify(arr,n,i);
    }
}

void heapSort(int arr[], int n){
    buildHeap(arr,n);
    for(int i=n-1;i>=1;i--){
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0); // it will bring latter largest element on left
    }                        // as former largest element is placed at its correct position at end
}

int main(){
    int arr[] = {10,15,50,4,20};
    heapSort(arr,5);
    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
    }
    return 0;
}