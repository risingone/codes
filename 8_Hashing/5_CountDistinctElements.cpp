#include<bits/stdc++.h>
using namespace std;

// Naive soln TC: O(n^2) SC: O(1)
int countDist(int arr[], int n){
    int res=0;
    for(int i=0;i<n;i++){ //traverse for each element
        bool flag=false;
        for(int j=0;j<i;j++){ // check if it occured before
            if(arr[i]==arr[j]){
                flag=true; // update flag
                break;
            }
        }
        if(flag==false) res++; // update res only for 1st occurence of element
    }
    return res;
}

// Effective soln TC: O(n) SC: O(n)
int countDistinct(int arr[], int n){
    // unordered_set<int> s;
    // for(int i=0;i<n;i++){
    //     s.insert(arr[i]);
    // }
    unordered_set<int> s(arr, arr+n); // short way to copy an array in a set
    return s.size();
}

int main(){
    int arr[] = {15,12,13,12,13,13,18};
    int n=7;
    cout << countDist(arr,n) << endl;
    cout << countDistinct(arr,n) << endl;
    return 0;
}