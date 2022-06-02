/*We have to find length of Longest Common Subsequence(consq. occ ele. in arr)*/
#include<bits/stdc++.h>
using namespace std;

// M-1: Naive approach O(n^2) to get length
int lis(int arr[],int n){
    int lis[n];
    // as each ele. it self form a subseq. of len. 1
    lis[0]=1;
    for(int i=1;i<n;i++){
        lis[i]=1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && lis[i]<lis[j]+1){ // to store maxm. len. of the subseq. in lis[i]
                lis[i]=lis[j]+1;
            }
        }
    }
    // in case you also want to print LIS
    int ind=0;
    int maxi=lis[0];
    // get last ele. index and length of LIS
    for(int i=n-1;i>=0;i--){
        if(lis[i]>maxi){
            maxi=lis[i];
            ind=i;
        }
    }
    vector<int> sq;
    sq.push_back(arr[ind]);
    for(int i=ind-1;i>=0;i--){ // we search before index of last occ. ele. of LIS
        if(lis[i]+1 == lis[ind] && arr[i]<arr[ind]){ // if its lis[i]==lis[ind]-1 and val. also <arr[ind]
            ind=i;                                   // update ind and add it to
            sq.push_back(arr[ind]);                  // LIS
        }
    }
    reverse(sq.begin(),sq.end()); // as we have LIS in rev. order
    for(auto it:sq){
        cout << it << " ";
    }
    cout << endl;
    // we can also return maxi if we are printing the LIS too
    return *max_element(lis,lis+n); // it returns iterator to the maxm. val. in range
}

// M-2 O(nlogn)
// remember it is not gauranted that seq will hold LIS although length of both will be same
//  for-> 50 3 10 7 40 80 , it will go like
//        50
//        3
//        3 10
//        3 7
//        3 7 40
//        3 7 40 80
int lis2(int arr[],int n){
    vector<int> seq;
    seq.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(seq.back()<arr[i]){ // add it if it is > than ele. in seq.
            seq.push_back(arr[i]);
        }
        else{ // otherwise replace it with ele. which is immediate > or = it
            int ind = lower_bound(seq.begin(),seq.end(),arr[i])-seq.begin(); // to find ind. of it or ele. just
            seq[ind] = arr[i];                                               // greater than it and replace with it
        }
    }
    return seq.size();
}

// Practice Questions
// Leetcode 354: Russian Doll Envelopes

int main(){
    int n=6;
    int arr[] = {50,3,10,7,40,80}; // 3 7 40 80 or 3 10 40 80
    cout << lis(arr,n) << endl;
    cout << lis2(arr,n) << endl;
    return 0;
}