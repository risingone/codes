#include<bits/stdc++.h>
using namespace std;

void print1toN(int n){
    if(n==0) return;
    print1toN(n-1);
    cout << n << endl;
}

void printNto1(int n){
    if(n==0) return;
    cout << n << endl;
    printNto1(n-1);
}

int main(){
    int n=5;
    cout << "===============Print 1 to N===============" << endl;
    print1toN(n);
    cout << "===============Print N to 1===============" << endl;
    printNto1(n); // it is Tail recursive function as function has nothing to do after last call
    return 0;
}