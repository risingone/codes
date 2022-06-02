#include<bits/stdc++.h>
using namespace std;

// naive approach O(n^2)
bool isPair(int arr[],int n,int sum){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == sum) return true;
        }
    }
    return false;
}
/* We can sort and then apply 2ptr approach but it will take O(n logn)*/

// efficient approach
bool isPair1(int arr[],int n,int sum){
    unordered_set<int> h;
    for(int i=0;i<n;i++){
        if(h.find(sum-arr[i])!=h.end()) // if sum-arr[i] present return true
            return true;
        else
            h.insert(arr[i]);           // else insert arr[i] in set
    }
    return false;
}

int main(){
    int arr[]={3,2,8,15,-8};
    int n=5;
    int sum = 17;
    cout << isPair(arr,n,sum) << endl;
    cout << isPair1(arr,n,sum) << endl;
    return 0;
}