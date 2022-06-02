#include<bits/stdc++.h>
using namespace std;

//naive solution O(n^2)
int maxLen(int arr[],int n,int sum){
    int res=0;
    for(int i=0;i<n;i++){
        int curr_sum=0;
        for(int j=i;j<n;j++){ // check for every subarray
            curr_sum += arr[j];
            if(curr_sum==sum){ // if sum = curr_sum
                res = max(res,j-i+1); // update res
            }
        }
    }
    return res;
}

// efficient solution
int maxlen(int arr[],int n,int sum){
    unordered_map<int,int> ump;
    int res=0;
    int preSum=0;
    for(int i=0;i<n;i++){
        preSum += arr[i];                             // cal. preSum
        if(preSum==sum) res=i+1;                      // if preSum==sum -> res=i+1
        if(ump.find(preSum-sum)!=ump.end()){         // if preSum - sum is present 
            res = max(res,i-ump[preSum-sum]);        // curr. index - index of preSum's occ. is length
        }
        else{
            ump.insert({preSum,i});
        }
    }
    return res;
}

int main(){
    int arr[]={8,3,1,5,-6,6,2,2};
    int n=8;
    int sum=4;
    cout << maxLen(arr,n,sum) << endl;
    cout << maxlen(arr,n,sum) << endl;
    return 0;
}