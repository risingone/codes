/*Count number of triplets with given sum*/
#include<bits/stdc++.h>
using namespace std;
int countPairs(int arr[],int left,int right,int x){
    int count=0;
    while(left<right){
        if(arr[left]+arr[right] == x){
            count++;
            left++;
            right--;
        }
        else if((arr[left]+arr[right])<x){
            left++;
        }
        else{
            right--;
        }
    }
    return count;
}
int countTriplets(int arr[],int n,int x){
    int count=0;
    for(int i=0;i<n;i++){
        count += countPairs(arr,i+1,n-1,x-arr[i]);
    }
    return count;
}
int main(){
    int A[]={0,1,2,3,4};
    int n=sizeof(A)/sizeof(A[0]);
    int x=5;
    cout << countTriplets(A,n,x) << endl;
    return 0;
}