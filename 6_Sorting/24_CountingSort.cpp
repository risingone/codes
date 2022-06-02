#include<bits/stdc++.h>
using namespace std;

// naive implementation, it can't be implemented in general as it uses index
void countSort(int arr[],int n,int k){  //O(n+k)
    //part-1
    int count[k];  // we make an array of size=range of numbers
    for(int i=0;i<k;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){ // the freq array count represent number via index and its occurence at that index
        count[arr[i]]++;
    }
    //part-2
    int index=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<count[i];j++){
            arr[index]=i;  // now we copy elements as per their occurence
            index++;       // in count array in the sorted fashion
        }
    }
}

// Genral Purpose Implementation
void countSort1(int arr[], int n,int k){
    //part-1 will be same
    int count[k];
    for(int i=0;i<k;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    //part-2 make prefixSum array of count
    for(int i=1;i<k;i++){
        count[i] += count[i-1];
    }
    //part-3
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    // part-4 copy result back
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

int main(){
    int arr[] = {1,4,4,1,0,1};
    // countSort(arr,6,5);
    countSort1(arr,6,5);
    for(int i=0;i<6;i++){
        cout << arr[i] << " ";
    }
    return 0;
}