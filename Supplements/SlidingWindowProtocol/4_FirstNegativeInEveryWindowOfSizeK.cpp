#include<bits/stdc++.h>
using namespace std;

vector<int> getNegative(vector<int> &arr,int &k){
    vector<int> res;
    deque<int> dq;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0) dq.push_back(i);
        if(!dq.empty() && dq.front()==i-k) dq.pop_front();
        if(i>=(k-1)){
            if(dq.empty()){
                res.push_back(0);
            } else{
                res.push_back(arr[dq.front()]);
            }
        }
    }
    return res;
}

vector<int> getNegative2(vector<int> &arr, int &k){
    vector<int> res;
    deque<int> dq;
    int i=0,j=0;
    while(j<arr.size()){
        if(arr[j]<0){
            dq.push_back(j);
        }
        if((j-i+1)<k) j++;
        else if((j-i+1)==k){
            if(dq.empty()) res.push_back(0);
            else{ 
                res.push_back(arr[dq.front()]);
                if(dq.front()==i) dq.pop_front();
            }
            i++;
            j++;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {12,-1,-7,8,-15,30,16,28}; // print 0 if no -ve no is present
    int k=3;
    vector<int> ans = getNegative(arr,k);
    for(auto &it: ans){
        cout << it << " ";
    }
    cout << endl;
    vector<int> ans2 = getNegative2(arr,k);
    for(auto &it: ans2){
        cout << it << " ";
    }
    return 0;
}