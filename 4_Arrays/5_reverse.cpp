/*To reverse an given Array*/
#include <bits/stdc++.h>
using namespace std;
void reverse(int arr[], int n){
    int low=0, high=n-1;
    while(low<high){
        int temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        low++;
        high--;
    }
}
int main(){
    int A[]={10,5,7,30};
    reverse(A,4);
    for(int i=0;i<4;i++){
        cout << A[i] << " ";
    }
    return 0;
}