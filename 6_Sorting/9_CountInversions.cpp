/*A pair(arr[i], arr[j]) forms an inversion when
        i < j
    and arr[i] > arr[j]   */
#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int l,int mid,int h){
    int n1=mid-l+1,n2=h-mid;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+i+1];
    }
    int i=0,j=0,k=l,inv=0;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            arr[k]=a[i];
            i++; k++;
        } else{              // inversion occurs when a[i]>b[j]
            inv += n1-i;     // and will be equal to n1-i as
            arr[k]=b[j];     // divided arr are in sorted fashion
            j++; k++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        i++; k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++; k++;
    }
    return inv;
}

int mergeSort(int arr[],int l,int r){ //modified mergeSort to calculate inversion
    if(l>=r) return 0;
    int mid = l + (r-l)/2;
    int inv = mergeSort(arr,l,mid);
    inv += mergeSort(arr,mid+1,r);
    inv += merge(arr,l,mid,r);
    return inv;
}

int main(){
    int arr[] = {2,4,1,3,5};
    cout << mergeSort(arr,0,4) << endl;
    return 0;
}