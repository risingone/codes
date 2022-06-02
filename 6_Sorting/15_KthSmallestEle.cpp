#include<bits/stdc++.h>
using namespace std;
// int KthSmallest(int arr[],int n,int k){ //naive O(n log n)
//     sort(arr,arr+n);
//     return arr[k-1];
// }

int partition(int arr[],int l,int h){ // Lomuto
    int i=l-1;
    int pivot = arr[h]; // always last element
    for(int j=l;j<h;j++){
        if(arr[j]<pivot){
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    for(int i=l;i<=h;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return (i+1);
}
int KthSmallest(int arr[],int n,int k){ // efficient approach O(n)
    int l=0,r=n-1;
    while(l<=r){
        int p = partition(arr,l,r); // we will use Lomuto partition as it gives 
        if(p==k-1) return arr[p];   // correct position for pivot
        else if(p>k-1) r=p-1;       // update r and l
        else{
            l=p+1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {30,20,5,10,8};
    cout << KthSmallest(arr,5,4) << endl;
    return 0;
}