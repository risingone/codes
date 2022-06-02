/*Given an array of integers and a number k, find the maximum sum of k consecutive elements
e.g: i/p-> arr[] = {1,8,-30,-5,20,7} 
     o/p-> 45*/
#include<bits/stdc++.h>
using namespace std;
// M-1 naive approach O((n-k)*k)
int maxSum(int arr[],int n,int k){
    int max_sum=INT_MIN;           // to store max. possible sum
    for(int i=0;i<n-k+1;i++){  // travese first n-k elements 
        int sum=0;
        for(int j=0;j<k;j++){ // for eack element cal. sum of k elements
            sum+=arr[i+j];
        }
        max_sum = max(sum,max_sum); //update max_sum if sum > max_sum 
    }
    return max_sum;
}
// M-2 efficient approach
int maxSum2(int arr[],int n,int k){
    int curr_sum=0;
    for(int i=0;i<k;i++){    // we store sum of first k elements in curr_sum
        curr_sum += arr[i];
    }
    int max_sum=curr_sum;  // load max_sum
    for(int i=k;i<n;i++){ //we traverse through remaining elements
        curr_sum += (arr[i]-arr[i-k]); // we add curr. element to curr_sum & remove first appearing ele. in curr_sum
        max_sum = max(max_sum,curr_sum); // update max_sum if required
    }
    return max_sum;
}
int main(){
    int A[]={1,8,30,-5,20,7};
    cout << maxSum(A,6,3) << endl;
    cout << maxSum2(A,6,3) << endl;
    return 0;
}