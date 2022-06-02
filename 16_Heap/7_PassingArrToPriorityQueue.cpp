#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {10,5,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Max Heap: " << endl;
    // O(n) as it calls buildheap while inserting 1 by 1 takes O(nlogn) time
    priority_queue<int> pq(arr,arr+n);
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    // we can implement min heap by multiplying by (-1) before insserting and also during retrieving
    cout << "Min Heap: " << endl;
    for(int i=0;i<n;i++){
        arr[i]=-arr[i];
    }
    priority_queue<int> pq2(arr,arr+n);
    while(!pq2.empty()){
        cout << -pq2.top() << " ";
        pq2.pop();
    }
    return 0;
}