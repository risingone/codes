/*We are given 2 binary subarrays of same sizes and we have to find longest
  common span -> have same starting and ending point and same sum(smae no. of 0 and 1) of elements in b/w*/
#include<bits/stdc++.h>
using namespace std;

// naive solution O(n^2)
int maxCommon(int arr1[],int arr2[],int n){
    int res=0;
    for(int i=0;i<n;i++){
        int sum1=0,sum2=0;
        for(int j=i;j<n;j++){
            sum1 += arr1[j];
            sum2 += arr2[j];
            if(sum1==sum2){ // check if both have same sum
                res = max(res,j-i+1); // update res
            }
        }
    }
    return res;
}

// efficient solution
int maxCommon1(int arr1[],int arr2[],int n){
    int temp[n];
    for(int i=0;i<n;i++){
        temp[i] = arr1[i]-arr2[i];
    }
    // Longest Subarr with 0 sum
    unordered_map<int,int> ump;
    int res=0,pre_sum=0;
    for(int i=0;i<n;i++){
        pre_sum += temp[i];
        if(pre_sum==0) res=i+1;
        if(ump.find(pre_sum)!=ump.end()){
            res = max(res,i-ump[pre_sum]);
        }
        else{
            ump.insert({pre_sum,i}); // insert pair
        }
    }
    return res; 
}

int main(){
    int n=6;
    int arr1[] = {0,1,0,0,0,0};
    int arr2[] = {1,0,1,0,0,1};
    cout << maxCommon(arr1,arr2,n) << endl;
    cout << maxCommon1(arr1,arr2,n) << endl;
    return 0;
}