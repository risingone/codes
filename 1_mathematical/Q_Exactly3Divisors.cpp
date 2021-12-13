#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n<=0) return false;
    if(n==2 || n==3) return true;
    if((n%2)==0 || (n%3)==0) return false;
    for(int j=5;j*j<=n;j+=6){
        if((n%j)==0 || (n%(j+2))==0) return false;
    }
}
int exactly3Divisors(int N)
{
    //as only square of prime numbers have exactly 3 divisors
    int count=0;
    for(int i=2;i*i<=N;i++){
        if(isPrime(i)){
            count++;
        }
    }
    return count;
}
int main(){
    int N=11;
    cout << exactly3Divisors(N) << endl;
    return 0;
}