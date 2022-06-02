#include<bits/stdc++.h>
using namespace std;

// radix sort internally uses count sort,it sorts on basis of digits and it is stable
void countingSort(int arr[],int n,int exp){
    int count[10],output[n]; // declare count arr of 10(0-9) digits, output to store sorted arr
    for(int i=0;i<10;i++){ count[i]=0;} // make count content 0
    for(int i=0;i<n;i++){ count[(arr[i]/exp)%10]++; } // store given place's bit occurence
    for(int i=1;i<10;i++){ count[i] += count[i-1]; } // make prefix sum array
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10] - 1] = arr[i]; // store array in sorted fashion
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){ arr[i] = output[i]; } // modify original array
}

void radixSort(int arr[], int n){
    int mx = arr[0];
    for(int i=1;i<n;i++){  //find maxm element in array
        if(arr[i]>mx){
            mx=arr[i];
        }
    }
    for(int exp=1;(mx/exp)>0;exp *= 10){ // sort for every bit starting from LSB
        countingSort(arr,n,exp);
    }
}

int main(){
    int n=6;
    int arr[]={319,212,6,8,100,50};
    radixSort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}