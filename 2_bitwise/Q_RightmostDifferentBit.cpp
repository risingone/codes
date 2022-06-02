/*Two numbers are given, find the right most different bit among them*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned int m=11,n=9; // 1011 and 1001
    m=m^n; // now only different bits will be set
    if(m==0) return 0;
    int count=1;
    while((m&1)==0){
        count++;
        m=m>>1;
    }
    cout << count << endl;
    return 0;
}