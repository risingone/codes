/* Given n ranges, find the maximum appearing element in the ranges with all elements <1000 
e.g: i/p-> L[] = {1,2,5,15}
           R[] = {5,8,7,18}
     o/p-> 5*/
#include<bits/stdc++.h>
using namespace std;
int maxOcc(int L[],int R[],int n){
    int arr[1000]={0};     //to store freq. of each element
    for(int i=0;i<n;i++){
        arr[L[i]]++;       // it increases freq. of left side element of range
        arr[R[i]+1]--;     // it decreases freq. of right side element to balance the freq.
    }                      // while we fill it using prefix sum 
    int max=arr[0],res=0;  // max to store maxm. freq. & res to store index(element)
    for(int i=1;i<1000;i++){
        arr[i] += arr[i-1];
        if(max<arr[i]){
            max=arr[i];
            res=i;
        }
    }
    return res;
}
int main(){
    int A[] = {1,2,3};
    int B[] = {3,5,7};
    cout << maxOcc(A,B,3) << endl;
    return 0;
}