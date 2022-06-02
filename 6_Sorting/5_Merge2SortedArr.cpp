#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int b[],int m,int n){
    int i=0,j=0;
    while(i<m && j<n){
        if(a[i] <= b[j]){
            cout << a[i] << " ";
            i++;
        } else{
            cout << b[j] << " ";
            j++;
        }
    }
    while(i<m){
        cout << a[i] << " ";
        i++;
    }
    while(j<n){
        cout << b[j] << " ";
        j++;
    }
}
int main(){
    int arr1[]={6,7,9,11,16,21};
    int arr2[]={1,2,3,13,19};
    merge(arr1,arr2,6,5);
    return 0;
}