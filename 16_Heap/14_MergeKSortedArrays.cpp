#include<bits/stdc++.h>
using namespace std;

// M-1 Super Naive Approach
// First insert all elements into a single vector then sort that vector

vector<int> merge2Sorted(vector<int> &arr1,vector<int> &arr2){
    vector<int> ans;
    int m=arr1.size(),n=arr2.size();
    int i=0,j=0;
    while(i<m&&j<n){
        if(arr1[i]<arr2[j]){
            ans.push_back(arr1[i++]);
        } else{
            ans.push_back(arr2[j++]);
        }
    }
    while(i<m){
        ans.push_back(arr1[i++]);
    }
    while(j<n){
        ans.push_back(arr2[j++]);
    }
    return ans;
}

// M-2 Naive Approach
vector<int> mergeArr2(vector<vector<int>> &arr){
    int n=arr.size();
    vector<int>res = arr[0];
    for(int i =1;i<n;i++){
        res = merge2Sorted(res,arr[i]);
    }
    return res;
}

// M-3 Efficient Approach O(nklogk)
struct Triplet{
    int val,aPos,vPos;
    Triplet(int v,int ap,int vp){
        val=v;
        aPos=ap;
        vPos=vp;
    }
};

struct MyComp{
    bool operator()(Triplet &t1,Triplet &t2){
        return t1.val>t2.val;
    }
};

vector<int> mergeArr(vector<vector<int>> &arr){
    vector<int> res;
    priority_queue<Triplet,vector<Triplet>,MyComp> pq;
    int k=arr.size();
    // insert 1st element of all k Sorted Arrays 
    for(int i=0;i<k;i++){
        pq.push(Triplet(arr[i][0],i,0));
    }
    // keep going till pq don't become empty
    while(!pq.empty()){
        Triplet curr=pq.top();    // take out top(minm val element)
        pq.pop();
        res.push_back(curr.val);  // place its value in res
        int ap=curr.aPos,vp=curr.vPos;
        if(vp+1<arr[ap].size()){   // if an element in same arr[] with +1 position is there
            pq.push(Triplet(arr[ap][vp+1],ap,vp+1)); // add it to pq
        }
    }
    return res; // return res
}

int main(){
    vector<vector<int>> arr = {{10,20,30},
                                {5,15},
                                {1,9,11,18}};
    // Most efficient approach
    vector<int> res = mergeArr(arr);
    for(auto &it: res){
        cout << it << " ";
    }
    cout << endl;
    // Naive approach
    vector<int> res1= mergeArr2(arr);
    for(auto &it: res1){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}