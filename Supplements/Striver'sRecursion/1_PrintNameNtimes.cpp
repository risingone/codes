#include<bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n) (auxilary space)
void printName(int i,int &n){
    if(i>n) return;
    cout << "Yash" << endl;
    printName(i+1,n);
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    printName(1,n);
    return 0;
}