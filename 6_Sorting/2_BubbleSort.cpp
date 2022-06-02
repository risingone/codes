#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        bool swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped = false) break;
    }
}
int main(){
    int arr[] = {3,2,6,1,7};
    bubbleSort(arr,5);
    for(int x: arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}