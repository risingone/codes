#include<bits/stdc++.h>
using namespace std;

// Naive Method: O(n^2)
void printCeiling(int arr[],int n){
    cout << -1 << " "; // as 1 element won't have a ceiling
    for(int i=1;i<n;i++){
        int diff=INT_MAX;
        for(int j=0;j<i;j++){
            if(arr[j]>=arr[i]){
                diff = min(diff,arr[j]-arr[i]);
            }
        }
        if(diff==INT_MAX){
            cout << -1 << " ";
        } else{
            cout << (arr[i]+diff) << " ";
        }
    }
}

// M-2: O(nlogn)
void printCeiling2(int arr[],int n){
    cout << -1 << " ";
    set<int> s;
    s.insert(arr[0]);
    for(int i=1;i<n;i++){
        auto it=s.lower_bound(arr[i]);
        if(it!=s.end()){
            cout << *it << " ";
        } else{
            cout << -1 << " ";
        }
        s.insert(arr[i]);
    }
}

int main(){
    int n=6;
    int arr[] = {2,8,30,15,25,12};
    printCeiling(arr,n);
    cout << endl;
    printCeiling2(arr,n);
    return 0;
}