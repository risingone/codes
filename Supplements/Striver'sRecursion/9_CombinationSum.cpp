#include<bits/stdc++.h>
using namespace std;

// LC- 39
class Solution{
    void findCombination(int ind,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        // pick up the element
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findCombination(ind,target-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        // not pick
        findCombination(ind+1,target,arr,ans,ds);
    }
    public:
        vector<vector<int>> combinationSum(vector<int> &candidates,int target){
            vector<vector<int>> ans;
            vector<int> ds;
            findCombination(0,target,candidates,ans,ds);
            return ans;
        }
};

int main(){
    Solution s;
    vector<int> candidates = {2,3,5};
    int target = 8;
    vector<vector<int>> res = s.combinationSum(candidates,target);
    for(auto &v: res){
        for(auto &it: v){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}