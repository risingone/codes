#include<bits/stdc++.h>
using namespace std;
void selectSort(int arr[],int n){ // but it uses O(n) extra space
    int temp[n];
    for(int i=0;i<n;i++){         // we take minimum element in present array
        int min_ind = 0;          // and place it in front
        for(int j=1;j<n;j++){
            if(arr[j]<arr[min_ind]){
                min_ind=j;
            }
        }
        temp[i] = arr[min_ind];
        arr[min_ind] = INT_MAX;
    }
    for(int i=0;i<n;i++) {
        arr[i] = temp[i];
    }
}
void effselectSort(int arr[],int n){ // space complexity: O(1)
    for(int i=0;i<n;i++){
        int min_ind = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_ind]) min_ind = j;
        }
        swap(arr[i],arr[min_ind]);
    }
}
int main(){
    int arr[] = {4,1,2,7,3,2};
    // selectSort(arr,6);
    effselectSort(arr,6);
    for(int x: arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}