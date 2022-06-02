#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n){ // we have sorted array on left before ith index
    for(int i=1; i<n; i++){           // we take an element from unsorted part
        int key = arr[i];             // and place it in sorted part
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int A[]={9,8,7,6,5,4};
    insertionSort(A,6);
    for(int i: A){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}