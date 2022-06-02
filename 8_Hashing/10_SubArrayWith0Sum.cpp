#include<bits/stdc++.h>
using namespace std;
// naive approach O(n^2)
bool is0Subarray(int arr[],int n){
    for(int i=0;i<n;i++){
        int curr_sum=0;
        for(int j=i;j<n;j++){
            curr_sum += arr[j];
            if(curr_sum==0) return true;
        }
    }
    return false;
}
// efficient solution
bool is0Subarray1(int arr[],int n){
    unordered_set<int> s;
    int pre_sum=0;
    for(int i=0;i<n;i++){
        pre_sum += arr[i];
        if(s.find(pre_sum)!=s.end()){ // if pre_sum has already occured it means
            return true;              // sum of ele. from that index to curr index is 0
        }
        if(pre_sum==0) return true; // if presum is 0
        s.insert(pre_sum);
    }
    return false;
}

int main(){
    int arr[]={1,4,13,-3,-10,5};
    int n=6;
    cout << is0Subarray(arr,n) << endl;
    cout << is0Subarray1(arr,n) << endl;
    return 0;
}