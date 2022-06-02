/* in it we have to calculate total no of set bits in numbers from 1 to n
Intution: for numbers before 2^x there are 2^(x-1)*x set bits */
#include<bits/stdc++.h>
using namespace std;
int greatPow(int n){
    int x=0;
    while((1<<x)<=n){
        x++;
    }
    return x-1;
}
int countSetBits(int n)
{
    // Your logic here
    if(n==0) return 0;
    int x=greatPow(n);
    // all set bits before 2^x
    int upto= x*(1<<(x-1)); // x*2^(x-1)
    // MSB(1's) b/w 2^x and n 
    upto += (n+1)-(1<<x); // n-(2^x) +1
    return upto + countSetBits(n-(1<<x)); // call again for remaining bits
}

int main(){
    int n=17;
    cout << countSetBits(n) << endl;
    return 0;
}