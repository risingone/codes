#include<bits/stdc++.h>
using namespace std;

// naive approach O(n^2)
bool isSubArrSum(int arr[],int n,int sum){
    for(int i=0;i<n;i++){
        int curr_sum=0;
        for(int j=i;j<n;j++){
            curr_sum += arr[j];
            if(curr_sum==sum) return true;
        }
    }
    return false;
}

// efficient approach
bool isSubArrSum1(int arr[],int n,int sum){
    unordered_set<int> ust;
    int pre_sum=0;
    for(int i=0;i<n;i++){
        pre_sum += arr[i];
        if(pre_sum==sum) return true;                     // if pre_sum-sum is already present
        if(ust.find(pre_sum-sum)!=ust.end()) return true; // means sum from its occ. to curr. index is req. sum
        ust.insert(pre_sum);
    }
    return false;
}

int main(){
    int arr[]={5,8,6,13,3,-1};
    int n=6;
    int sum=22;
    cout << isSubArrSum(arr,n,sum) << endl;
    cout << isSubArrSum1(arr,n,sum) << endl;
    return 0;
}