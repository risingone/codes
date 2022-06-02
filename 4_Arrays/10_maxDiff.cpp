/*we have to calculate arr[j]-arr[i](Maximum Difference) such that j>i*/
#include<bits/stdc++.h>
using namespace std;
//M1: naive approach
int maxDiff(int arr[],int n){
    int res=arr[1]-arr[0];                   // store diff of first and second element in res
    for(int i=0;i<n-1;i++){                  // traverse the loop form 0 to n-2(for second last element)
        for(int j=i+1;j<n;j++){              // for each element find max diff 
            res = max(res,arr[j]-arr[i]);    // if it is > res update res
        }
    }
    return res;
}
//M2: more efficient-O(n)
int maxDiff2(int arr[], int n){
    int res=arr[1]-arr[0];             // store diff b/w first 2 elements in res
    int minVal=arr[0];                 // initialize minVal with first element
    for(int j=1;j<n;j++){              // traverse the array
        res = max(res, arr[j]-minVal); // if diff b/w minVal & arr[j] > res update res
        minVal = min(minVal,arr[j]);   // update minVal if arr[j]<minVal
    }
    return res;
}
int main(){
    int A[]={2,3,10,6,4,8,1};
    cout << maxDiff(A,7) << endl;
    cout << maxDiff2(A,7) << endl;
    return 0;
}