#include<bits/stdc++.h>
using namespace std;
int digitsInFactorial(int N)
{
    // code here
    if(N<=1) return 1;
    double ans=0;
    for(int i=2;i<=N;i++){ // log(N!)=log(1)+log(2)+....+log(N)
        ans += log10(i);
    }
    return floor(ans)+1;
}

int main(){
    int N=120; // o/p 199
    cout << digitsInFactorial(N) << endl;
    return 0;
}