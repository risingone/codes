#include<bits/stdc++.h>
using namespace std;
int naive_partition(int arr[],int l,int h,int p){
    int temp[h-l+1], index=0;
    for(int i=l;i<=h;i++){  //we will fill all elements < pivet in temp
        if(arr[i]<arr[p]){
            temp[index++]=arr[i];
        }
    }
    for(int i=l;i<=h;i++){
        if(arr[i]==arr[p]){
            temp[index++]=arr[i];
        }
    }
    int res=l+index-1; // index of pivot(-1 as index is 1 ahead of pivot)
    for(int i=l;i<=h;i++){
        if(arr[i]>arr[p]){
            temp[index++]=arr[i];
        }
    }
    for(int i=l;i<=h;i++){
        arr[i]=temp[i-l];
    }
    return res; //
}
int main(){
    int arr[] = {2,7,8,3,7};
    int p =1; // pivot
    cout << naive_partition(arr,0,4,p) << endl; //correct index of pivot
    for(int i=0;i<=4;i++){
        cout << arr[i] << " ";
    }
    return 0;
}