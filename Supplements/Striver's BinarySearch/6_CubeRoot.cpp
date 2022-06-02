#include<bits/stdc++.h>
using namespace std;

int cbRoot(int &n){
    int low=1,high=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid*mid*mid<=n){
            low=mid+1; 
        } else{
            high=mid-1;
        }
    }
    return high;
}

int main(){
    int n=111;
    cout << cbRoot(n) << endl;
    return 0;
}