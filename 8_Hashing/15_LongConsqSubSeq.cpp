#include<bits/stdc++.h>
using namespace std;
// naive approach O(nlogn)
int longestSub(int arr[],int n){
    sort(arr,arr+n);          // sort the array
    int res=1,curr=1;
    for(int i=1;i<n;i++){     // traverse it
        if(arr[i]==arr[i-1]+1){ // update curr
            curr++;
        }
        else if(arr[i]!=arr[i-1]){ // we use else if to deal with edge case
            res=max(res,curr);     // where arr[i]==arr[i-1] and arr[i+1]=arr[i]+1
            curr=1;
        }
    }
    return res;
}

// efficient solution O(n)
int longSub(int arr[],int n){
    unordered_set<int> ust(arr,arr+n);
    int res=1;
    for(auto &x: ust){
        if(ust.find(x-1)==ust.end()){ // if an element = x-1 is not present
            int curr=1;               // we only cal. len. for smallest ele. of consq ele.
            while(ust.find(x+curr)!=ust.end()){ // fint count of consq ele.
                curr++;
            }
            res=max(res,curr); // update res
        }
    }
    return res;
}

int main(){
    int arr[]={1,9,3,4,2,20};
    int n=6;
    cout << longestSub(arr,n) << endl;
    cout << longSub(arr,n) << endl;
    return 0;
}