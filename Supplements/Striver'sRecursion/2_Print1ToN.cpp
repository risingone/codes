#include<bits/stdc++.h>
using namespace std;

// Print 1 to N linearly
void print1toN(int i,int &n){
    if(i>n) return;
    cout << i << " ";
    print1toN(i+1,n);
}

// Print N to 1
void printNto1(int i,int &n){
    if(i<1) return;
    cout << i << " ";
    printNto1(i-1,n);
}

// Using backtracking
void print1toNBacktrack(int i,int &n){
    if(i<1) return;
    print1toNBacktrack(i-1,n);
    cout << i << " ";
}

void printNto1Backtrack(int i,int &n){
    if(i>n) return;
    printNto1Backtrack(i+1,n);
    cout << i << " ";
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    print1toN(1,n);
    cout << endl;
    printNto1(n,n);
    cout << endl;
    print1toNBacktrack(n,n);
    cout << endl;
    printNto1Backtrack(1,n);
    cout << endl;
    return 0;
}