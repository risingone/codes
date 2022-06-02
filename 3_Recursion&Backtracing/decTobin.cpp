/* To convert a decimal number into its binary representation*/
#include<bits/stdc++.h>
using namespace std;
void fun(int n){
    if(n==0) return;
    fun(n/2);
    cout << n%2; // print while coming back
}
int main(){
    int n;
    cout << "Enter decimal number: ";
    cin >> n;
    fun(n);
    return 0;
}