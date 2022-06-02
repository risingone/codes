#include<bits/stdc++.h>
using namespace std;

// M-1: Naive O(n^2)
void printMaxK(int arr[],int n,int k){
    for(int i=0;i<n-k+1;i++){
        int mx=arr[i];
        for(int j=i+1;j<i+k;j++){
            mx=max(arr[j],mx);
        }
        cout << mx << " ";
    }
    cout << endl;
}

// M-2: Efficient O(n)
void printMaxK2(int arr[],int n,int k){
    deque<int> dq;
    for(int i=0;i<k;i++){
        // remove elements < arr[i] from deque
        while(!dq.empty() && arr[i]>=arr[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    for(int i=k;i<n;i++){
        cout << arr[dq.front()] << " ";
        // to remove element which is no longer part of sliding window
        while(!dq.empty() && dq.front()<=(i-k)) dq.pop_front();
        while(!dq.empty() && arr[i]>=arr[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " "; // for last element
    cout << endl;
}

int main(){
    int n=7,k=3;
    int arr[] ={10,8,5,12,15,7,6};
    printMaxK(arr,n,k);
    printMaxK2(arr,n,k);
    return 0;
}