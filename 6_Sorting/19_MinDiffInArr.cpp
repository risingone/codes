#include<bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[],int n){ // naive O(n^2) approach
    int res=INT_MAX;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            res = min(res,abs(arr[i]-arr[j]));
    return res;
}

int getMinDiff1(int arr[],int n){ // O(n log n)
    int res=INT_MAX;
    sort(arr,arr+n);  // first sort
    for(int i=0;i<n-1;i++){ // then check diff b/w consq elements
        res = min(res,(arr[i+1]-arr[i]));
    }
    return res;
}

int main(){
    int arr[] = {1,8,12,5,18};
    cout << getMinDiff(arr,5) << endl;
    cout << getMinDiff1(arr,5) << endl;
    return 0;
}