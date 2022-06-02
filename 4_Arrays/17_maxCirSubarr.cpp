/*To calculate max. sum of circular subarray present in an array*/
#include<bits/stdc++.h>
using namespace std;
//M-1 naive approach O(n^2)
int maxCircularSum(int arr[],int n){
    int res=arr[0];
    for(int i=0;i<n;i++){
        int curr_max=arr[i],curr_sum=arr[i]; // for each arr element update curr_max & curr_sum with it
        for(int j=1;j<n;j++){                // and traverse remaining elements in circular manner
            int index = (i+j)%n;             // by using modulo operator
            curr_sum += arr[index];          // keep on adding traversed elements
            curr_max = max(curr_max,curr_sum);// update curr_max if curr_sum>curr_max
        }
        res = max(res,curr_max);  // update res if for ith element curr_max>res
    }
    return res;
}
// M-2 efficient sol. O(n)
/* Idea: Take the maximum of the following:
         a) Max. sum of a normal subarr.(Kadane algo)
         b) Max. sum of a circular subarr.
          =) To get it we have to subtract sum of min. subarray from sum of array*/
int normalMaxSum(int arr[],int n){  // kadane's algo
    int res=arr[0],endSum=arr[0];
    for(int i=1;i<n;i++){
        endSum = max(arr[i],endSum+arr[i]);
        res = max(res,endSum);
    }
    return res;
}
int  maxCircularSum2(int arr[],int n){
    int max_normal = normalMaxSum(arr,n); // normal sum of max subarray
    if(max_normal<0)  //as for arr[] = {-5,-3} code give below will give 0 which is false
        return max_normal;
    int arr_sum=0;             //to store sum of whole array
    for(int i=0;i<n;i++){
        arr_sum += arr[i];
        arr[i] = -arr[i];      // we mul. every ele. with -1 so that sum of min. subarray become max sum 
    }
    int max_circular = arr_sum + normalMaxSum(arr,n); // it equals =) arr. sum - min subarr.
    return max(max_normal,max_circular);
}
int main(){
    int A[]={3,-4,5,6,-8,7};
    cout << maxCircularSum(A,6) << endl;
    cout << maxCircularSum2(A,6) << endl;
    return 0;
}