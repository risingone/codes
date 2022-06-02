/*To remove the duplicate elements from an sorted Array*/
#include<bits/stdc++.h>
using namespace std;
int remDups(int arr[],int n){
    int temp[n];   //temporary array to store array without duplicates
    temp[0]=arr[0]; //copy 1 element
    int res=1;
    for(int i=1;i<n;i++){
        if(temp[res-1] != arr[i]){ // load temp array
            temp[res]=arr[i];
            res++;
        }
    }
    for(int i=0;i<res;i++){ //now load temp in original array
        arr[i]=temp[i];
    }
    return res; //return size of array without duplicates
}
int effremDups(int arr[],int n){//it doesn't use O(n)space like above function it takes O(1) space
    int res=1;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[res-1]){
            arr[res]=arr[i];
            res++;
        }
    }
    return res;
}
int main(){
    int A[]={10,20,20,30,30,30};
    // int n=remDups(A,6);
    int n=effremDups(A,6);
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    return 0;
}