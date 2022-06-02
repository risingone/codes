#include<bits/stdc++.h>
using namespace std;

void bucketSort(int arr[],int n,int k){
    int max_val = arr[0];
    for(int i=1;i<n;i++){ // find maxm
        max_val=max(max_val,arr[i]);
    }
    max_val++; // as we also have to store maxm val in bucket
    vector<int> bkt[k]; //an array of size k where each element is a vector(bucket)
    for(int i=0;i<n;i++){ // fill Bucket
        int bi = (k*arr[i])/max_val;
        bkt[bi].push_back(arr[i]);
    }
    for(int i=0;i<k;i++){ // sort individual bucket(vector)
        sort(bkt[i].begin(),bkt[i].end());
    }
    int index=0;
    for(int i=0;i<k;i++){ // join buckets
        for(int j=0;j<bkt[i].size();j++){
            arr[index++]=bkt[i][j];
        }
    }
}

int main(){
    int n=9,k=4;
    int arr[] = {20,88,10,85,75,95,18,82,60};
    bucketSort(arr,n,k);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}