#include<bits/stdc++.h>
using namespace std;

// M-1 Creating a maxHeap of n items and then taking out first k
// TC: O(n + klog(n))

//M-2 O(k + (n-k)*logk)
void printKLarge(int arr[],int &n,int &k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]>pq.top()){ // if curr. item > top of min heap 
            pq.pop();        // pop out top item
            pq.push(arr[i]); // and push current item
        }                    // otherwise ignore
    }
    // print k largest items present in min heap
    // O(k), we assume printing order doesn't matter
    while(!pq.empty()){ // here it will be klogk but if we implement ourself we can make it k
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main(){
    int k=2;
    int arr[] = {5,15,10,20,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    printKLarge(arr,n,k);
    return 0;
}