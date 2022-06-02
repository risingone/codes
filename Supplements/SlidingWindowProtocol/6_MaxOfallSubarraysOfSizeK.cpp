#include<bits/stdc++.h>
using namespace std;

vector<int> getMax(vector<int> &arr,int &k){
    vector<int> res;
    deque<int> dq;
    int i=0,j=0;
    while(j<arr.size()){
        while(!dq.empty()&&(arr[j]>arr[dq.back()])) dq.pop_back();
        dq.push_back(j);

        if((j-i+1)<k) j++;
        else if((j-i+1)==k){
            res.push_back(arr[dq.front()]);
            if(dq.front()==i) dq.pop_front();
            i++;
            j++;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int> ans = getMax(arr,k);
    for(int &x: ans){
        cout << x << " ";
    }
    return 0;
}