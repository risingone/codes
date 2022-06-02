/*We have to distribut choclates in such a way thst difference b/w people who get mast and least
is minimum*/
#include<bits/stdc++.h>
using namespace std;
int minDiff(int arr[],int n,int m){
    if(m>n) return -1;
    sort(arr,arr+n); // first we sort the array
    int res = arr[m-1] - arr[0];
    for(int i=1;(i+m-1)<n;i++){   // we traverse upto n-(m-1)
        res = min(res,(arr[i+m-1]-arr[i])); // update res
    }
    return res;
}
int main(){
    int arr[] = {7,3,2,4,9,12,56};
    int m=3;
    cout << minDiff(arr,7,m) << endl;
    return 0;
}