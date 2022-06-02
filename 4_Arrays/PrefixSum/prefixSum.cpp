/*Given a fixed array and multiple queries of following types on the array, how to efficiently perform the queries
e.g: i/p: arr[] = {3,8,3,9,6,5,4}
Queries getSum(0,2)
        getSum(1,3)
        getSum(2,6)*/
#include<bits/stdc++.h>
using namespace std;
int getSum(int prefix_sum[],int l,int r){
    if(l!=0){    // if l>0 sum will be prefix_sum[r]-prefix_sum[l-1]
        return prefix_sum[r]-prefix_sum[l-1];
    }
    else{   // else it will be equal to prefix_sum[r]
        return prefix_sum[r];
    }
}
int main(){
    int arr[]={2,8,3,9,6,5,4};
    int n=7;
    int prefix_sum[n]; //{2,10,13,22,28,33,37}
    prefix_sum[0]=arr[0];
    for(int i=1;i<n;i++){ //O(n)
        prefix_sum[i] = prefix_sum[i-1]+arr[i];
    }
    cout << getSum(prefix_sum,0,2) << endl;
    cout << getSum(prefix_sum,1,3) << endl;
    cout << getSum(prefix_sum,2,6) << endl;
    return 0;
}