/*To calculate maximum sum of a subarray*/
#include<bits/stdc++.h>
using namespace std;
//M-1 naive approach O(n^2)
int maxSum(int arr[],int n){
    int res=arr[0];
    for(int i=0;i<n;i++){ //for each element 
        int curr=0;      // traverse till end
        for(int j=i;j<n;j++){ // update curr
            curr += arr[j];   // acc. to it update res
            res = max(res,curr);
        }
    }
    return res;
}
//M-2 O(n) Kadane's algorithm
int maxSum2(int arr[],int n){
    int res=arr[0];                                  // store first element in result
    int maxEnding=arr[0];                            // maxEnding is also initialized to store sum
    for(int i=1;i<n;i++){                            // traverse through the array
        maxEnding = max(maxEnding+arr[i],arr[i]);    // update maxEnding as per condition
        res = max(res,maxEnding);                    // update result if required
    }
    return res;
}
int main(){
    int A[]={-3,8,-2,4,-5,6};
    cout << maxSum(A,6) << endl;
    cout << maxSum2(A,6) << endl;
    return 0;
}