/* Given an unsorted array of non-negative integers. Find if there is a subarray with given sum
e.g: i/p: arr[] = {1,4,20,3,10,5},given_sum=33
     o/p: Yes*/
#include<bits/stdc++.h>
using namespace std;
// M-1 naive approach O(n^2)
bool findSub(int arr[],int n,int given_sum){
    for(int i=0;i<n;i++){ 
        int sum=0;
        for(int j=i;j<n;j++){ //for each possible subarray
            sum += arr[j];    //we cal. its sum & compare it with
            if(sum==given_sum){//curr. sum
                return true;
            }
        }
    }
    return false;
}
//M-2 efficient approach
bool isSubSum(int arr[],int n,int sum){
    int curr_sum=arr[0],s=0;  // load curr_sum with 1st element & starting index s with 0
    for(int e=1;e<n;e++){     // e is the ending index
        //clean the prev. window
        while(curr_sum>sum && s<e-1){ //if curr_sum>sum we remove element & s<e-1 as we req atleast 1 elements
            curr_sum -= arr[s];       //sum in curr_sum
            s++;
        }
        if(curr_sum==sum) return true; // if we get the sum
        if(e<n){
            curr_sum += arr[e]; // keep on adding curr. element as curr_sum<sum
        }
    }
    return (curr_sum==sum);
}
int main(){
    int A[] = {10,4,20,3,11,5};
    cout << findSub(A,6,3) << endl;
    if(findSub(A,6,3)){
        cout << "Given sum Subarray is present" << endl;
    }
    else{
        cout << "Given sum Subarray is not present" << endl;
    }
    cout << isSubSum(A,6,3) << endl;
    return 0;
}