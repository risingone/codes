/*Find if there is a triplet a,b,c such that a^2 + b^2 = c^2*/
#include<bits/stdc++.h>
using namespace std;
bool pairExists(int arr[],int left,int right,int x){
    while(left<right){
        if((arr[left]*arr[left]+arr[right]*arr[right]) == x){
            return true;
        }
        else if((arr[left]*arr[left]+arr[right]*arr[right])<x){
            left++;
        }
        else{
            right--;
        }
    }
    return false;
}
bool tripletExists(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        int c2=arr[i]*arr[i];
        if(pairExists(arr,0,i-1,c2)){
            return true;
        }
    }
    return false;
}
int main(){
    int A[]={1,2,3,4,5}; // 3^2 + 4^2 = 5^2
    int n=sizeof(A)/sizeof(A[0]);
    cout << tripletExists(A,n);
    return 0;
}