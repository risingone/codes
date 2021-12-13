#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){  // gcd(a,b) = gcd(a-b,b)
    while(a!=b){
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}
int effgcd(int a,int b){
    if(b==0) return a;
    return effgcd(b, a%b);
}
int main(){
    int a,b;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " & " << b << " is: "
    << gcd(a,b) << endl;
    cout << "GCD of " << a << " & " << b << " is: "
    << effgcd(a,b) << endl;
    return 0;
}