#include<bits/stdc++.h>
using namespace std;
int grayToBinary(int n)
{
        
    // Your code here
    int ans=0;
    while(n){ // move till n become 0
        ans = ans^n;
        n = n>>1;
    }
    return ans;
}
int BinaryToGray(int n){
    int ans=n>>1; // as MSB remain same 
    return n^ans; // and ith bit Ex-Or with i+1 th
}
int main(){
    int n=15;
    cout << BinaryToGray(n) << endl;
    cout << grayToBinary(n) << endl;
    return 0;
}