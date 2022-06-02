/*Given a sorted array and a sum, find if there is a triplet with given sum*/
#include<bits/stdc++.h>
using namespace std;
bool isPair(int arr[],int left,int right,int x){
    while(left<right){
        if((arr[left]+arr[right])==x) return true;
        else if((arr[left]+arr[right])>x){ //as sum is greater so move right ptr
            right--;
        }
        else{                              // as sum is less so move left ptr
            left++;
        }
    }
    return false;
}
bool isTriplet(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(isPair(arr,i+1,n-1,x-arr[i])){
            return true;
        }
    }
    return false;
}
int main(){
    int A[]={2,3,4,8,9,20,40};
    int n= sizeof(A)/sizeof(A[0]);
    int x=32;
    cout << isTriplet(A,n,x) << endl;
    return 0;
}