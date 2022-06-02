#include<bits/stdc++.h>
using namespace std;

// maxHeapify
void maxHeapify(int arr[],int n,int i){
    int largest=i,left=2*i+1,right=2*i+2;
    if(left<n && arr[left]>arr[largest]) largest=left;
    if(right<n && arr[right]>arr[largest]) largest=right;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        maxHeapify(arr,n,largest);
    }
}
//buildHeap
void buildHeap(int arr[],int n){
    // we start Heapify from parent of bottom rightmost element to root element
    for(int i=(n-2)/2;i>=0;i--){
        maxHeapify(arr,n,i);
    }
}

void heapSort(int arr[],int n){
    // Step :1 Make a Max Heap
    buildHeap(arr,n);
    // Step :2 Repeatedly swap root with last node, reduce heap
    // size by one and heapify,
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        maxHeapify(arr,i,0);
    }  
}

int main(){
    int arr[]={10,15,50,4,20};
    int n= sizeof(arr)/sizeof(arr[0]);
    heapSort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}