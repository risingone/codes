/* An element at index i will be present between the indices i-k to i+k*/
#include<bits/stdc++.h>
using namespace std;

// Naive Approach: Sort the Array O(nlogn)

// Effiecient Approach: O(klogk + (n-k)logk + klogk)
void sortk(int arr[],int n,int k){
    priority_queue<int, vector<int>, greater<int>> pq; // to make min Heap
    for(int i=0;i<=k;i++){// insert first k elements into min heap
        pq.push(arr[i]);
    }
    int index=0;
    for(int i=k+1;i<n;i++){ // traverse rest elements
        arr[index++]=pq.top(); // get minm element(top) out
        pq.pop();              // and add traversed element into min heap
        pq.push(arr[i]);
    }
    while(pq.empty()==false){ // get remaining elements out of min heap
        arr[index++] = pq.top();
        pq.pop();
    }
}

int main(){
    int k=2;
    int arr[] = {9,8,7,18,19,17};
    int n=sizeof(arr)/sizeof(arr[0]);
    sortk(arr,n,k);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}