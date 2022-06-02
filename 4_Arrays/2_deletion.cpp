/*To delete an element at specific position from Array*/
#include <bits/stdc++.h>
using namespace std;
int deleteEle(int arr[], int n, int x){ // n->size of array x->element to be deleted
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==x) break;
    }
    if(i==n) return n; // if element to be deleted is not present in array
    for(int j=i;j<n-1;j++){
        arr[j]=arr[j+1];
    }
    return n-1; // return new size as size will dec. by 1 after deletion
}
int main(){
    int A[]={3,8,12,5,6};
    int n = deleteEle(A,5,8);
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    return 0;
}