#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}

int fibo(int n){
    if(n<=1) return n;
    return fibo(n-1)+fibo(n-2);
}

int main(){
    cout << "Factorial" << endl;
    cout << fact(5) << endl;
    cout << "Fibonacci" << endl;
    cout << fibo(3) << endl;
    return 0;
}