#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to count the number of subarrays which adds to the given sum.
    int subArraySum(int arr[], int n, int sum)
    {
        //Your code here
        int count=0;
        int preSum=0;
        unordered_map<int,int> ump; // to store preSum
        for(int i=0;i<n;i++){
            preSum += arr[i];
            if(preSum==sum) count++; // if preSum == sum, inc. count
            if(ump.find(preSum-sum)!=ump.end()){ // if preSum-sum is already present
                count += ump[preSum-sum];        // inc. count with its freq.
            }
            ump[preSum]++; // update freq. map for every iter.
        }
        return count;
    }
};

int main(){
    Solution s;
    int n=5,sum=-10;
    int arr[] = {10,2,-2,-20,10};
    cout << s.subArraySum(arr,n,sum) << endl;
    return 0;
}