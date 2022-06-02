#include<bits/stdc++.h>
using namespace std;

void getSum(int i,int sum){
    if(i<1){
        cout << sum << endl;
        return;
    }
    getSum(i-1,sum+i);
}

int getSum2(int n){
    if(n==0) return 0;
    return n+getSum2(n-1);
}

int getFact(int n){
    if(n==0) return 1;
    return n*getFact(n-1);
}

// TC: O(n) SC:O(n)
int main(){
    int n,sum=0;
    cout << "Enter n: ";
    cin >> n;
    getSum(n,sum);
    cout << getSum2(n) << endl;
    cout << getFact(n) << endl;
    return 0;
}