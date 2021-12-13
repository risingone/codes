/* To calculate x^n */
#include<bits/stdc++.h>
using namespace std;
int power(int x,int n){ //naive approach
    int res=1;
    for(int i=0;i<n;i++){
        res = res*x;
    }
    return res;
}
int pow(int x,int n){ //efficient solution
    if(n==0) return 1;
    int temp = pow(x,n/2);  
    temp *= temp;
    if(n&1){     // if n odd: pow(x,n-1)*x 
        return temp*x;
    }
    else             // else pow(x,n/2)*pow(x,n/2)
        return temp;
}
int itpower(int x,int n){
    int res=1;
    while(n>0){
        if(n&1)
            res = res*x;
        x *= x;
        n /= 2; // n=n>>1 to make it little bit fast
    }
    return res;
}
int main(){
    int x,n;
    cout << "Enter number and its power: ";
    cin >> x >> n;
    cout << power(x,n) << endl;
    cout << pow(x,n) << endl;
    cout << itpower(x,n) << endl;
    return 0;
}