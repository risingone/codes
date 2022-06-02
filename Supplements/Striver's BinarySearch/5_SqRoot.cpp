#include<bits/stdc++.h>
using namespace std;

int sqRoot(int &n){
    int low=1,high=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid*mid<=n){
            low=mid+1;
        } else{
            high=mid-1;
        }
    }
    return high;
}

int main(){
    int n=177;
    cout << sqRoot(n) << endl;
    return 0;
}