#include<bits/stdc++.h>
using namespace std;
int hoorePartition(int arr[], int l, int h){
    int pivot = arr[l];
    int i=l-1,j=h+1; // intialize left and right pointer
    while(true){
        do{
            i++;
        } while(arr[i]<pivot); // move i in forward dir and check 
        do{
            j--;
        } while(arr[j]>pivot); // move j in backward dir and check
        if(i>=j) return j;  // terminating condition
        swap(arr[i],arr[j]); // swap ith and jth element
    }
}
int main(){
    int arr[] = {5,3,8,4,2,7,1,10};
    cout << hoorePartition(arr,0,7) << endl;
    for(int i=0;i<8;i++){
        cout << arr[i] << " ";
    }
    return 0;
}