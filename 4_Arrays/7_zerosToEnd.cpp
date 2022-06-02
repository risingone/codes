/*To move all zeros to end of the array without disturbing sequence of other elements*/
#include<bits/stdc++.h>
using namespace std;
//naive approach O(n^2)
void moveToEnd(int arr[],int n){ 
    for(int i=0;i<n;i++){
        if(arr[i]==0){ //find 0 element
            for(int j=i+1;j<n;j++){ // find next non 0 element
                if(arr[j]!=0){
                    swap(arr[i],arr[j]); // swap them
                    break;
                }
            }
        }
    }
}
//more efficient: O(n)
void moveZeros(int arr[],int n){ 
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){ 
            swap(arr[i],arr[count]);
            count++;
        }
    }
}
int main(){
    int A[]={8,5,0,10,0,20};
    // moveToEnd(A,6);
    moveZeros(A,6);
    for(int x=0;x<6;x++){
        cout << A[x] << " ";
    }
    return 0;
}