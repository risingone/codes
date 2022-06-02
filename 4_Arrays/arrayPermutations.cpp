#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void permute(vector<int> &a,int idx){ // with distinct elements T- > O(n!)
    if(idx == a.size()){ // base case
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++){ 
        swap(a[i],a[idx]); // swap every element from i-(size-1) with idx
        permute(a,idx+1);  // calling for next idx
        swap(a[i],a[idx]); // swap back to avoid repetition
    }
    return;
}

/*void helper (vector<int> a, vector<vector<int>> &ans,int idx){
    if(idx == a.size()){
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++){
        if(i != idx && a[i] == a[idx]) // to run it ones for idx and avoid duplicates
            continue;
        swap(a[i],a[idx]);
        helper(a,ans,idx+1);
    }
}
vector<vector<int>> permute2(vector<int> nums){ // with repeating elements T- > O(n!)
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    helper(nums,ans,0);
    return ans;
}*/
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    permute(a,0);
    // sort(a.begin(),a.end());
    // do{                                        // using stl
    //     ans.push_back(a);
    // }while(next_permutation(a.begin(),a.end()));
    // vector<vector<int>> ans = permute2(a);
    for(auto v : ans){
        for(auto i: v)
            cout << i << " ";
            cout << "\n";
    }
}