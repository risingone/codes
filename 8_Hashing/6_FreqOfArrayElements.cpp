#include <bits/stdc++.h>
using namespace std;

// naive approach O(n^2)
void printFreq(int arr[],int n){
    for(int i=0;i<n;i++){ // traverse each ele.
        bool flag = false;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){ // check if it is its 1st occ.
                flag=true;
                break;
            }
        }
        if(flag) continue; // for second occ. of element code given below won't execute
        int freq = 1;
        for(int j=i+1;j<n;j++){ // to count freq of element
            if(arr[i]==arr[j]) freq++;
        }
        cout << arr[i] << " " << freq << endl;
    }
}

// efficient approach but it will print in random fashion
void countFreq(int arr[],int n){
    unordered_map<int,int> h;
    for(int i=0;i<n;i++) h[arr[i]]++; // store ele and freq in map
    for(auto e: h){
        cout << e.first << " " << e.second << endl;
    }
}

int main(){
    int arr[] = {10,12,10,15,10,20,12,12};
    int n=8;
    printFreq(arr,n);
    cout << "2nd Method" << endl;
    countFreq(arr,n);
    return 0;
}