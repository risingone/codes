#include<bits/stdc++.h>
using namespace std;
int getSum(int n){
    if(n<=9) return n;
    else
        return getSum(n/10) + n%10; // add n%10 and call for n/10
}
int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << getSum(n) << endl;
    return 0;
}