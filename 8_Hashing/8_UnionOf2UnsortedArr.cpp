#include<bits/stdc++.h>
using namespace std;

// efficient Solution O(m+n)
int unionCount(int a[],int b[],int m, int n){
    unordered_set<int> h(a,a+m); // copy both arrays in set h
    for(int i=0;i<n;i++){
        h.insert(b[i]);
    }
    return h.size(); // return its size
}

int main(){
    int a[]={15,20,5,10};
    int m=4;
    int b[]={15,15,15,20,10,7};
    int n=6;
    cout << unionCount(a,b,m,n) <<endl;
    return 0;
}