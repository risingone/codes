/*To Search in an infinite Sorted Array*/
#include<bits/stdc++.h>
using namespace std;
//M-1 naive approach- linear search O(position)
int search(int arr[], int x){
    int i=0;
    while(true){
        if(arr[i]==x) return i;
        if(arr[i]>x) return -1;
        i++;
    }
}
//M-2 
int bSearch(int arr[],int low,int high,int x){
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]>x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}
int search2(int arr[],int x){
    if(arr[0]==x) return 0;
    int i=1;
    while(arr[i]<x){
        i *= 2;
    }
    if(arr[i]==x) return i;
    return bSearch(arr,(i/2)+1,i,x); // binary search element in the range it might appear
}
int main(){
    int A[]={1,10,15,20,40,50,90,100,120,500};
    int x=15;
    cout << search(A,x) << endl;
    cout << search2(A,x) << endl;
    return 0;
}