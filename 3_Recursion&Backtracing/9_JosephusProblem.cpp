/*We will be given n people and kth person is killed repeatedly, we have to find the
last person alive*/
#include<bits/stdc++.h>
using namespace std;
int jos(int n,int k){       // k     <- 0
    if(n==1) return 0;      // k+1   <- 1
    else                    // k+2   <- 2
    return (jos(n-1,k)+k)%n;// as it will take circle from 0 every time
}
int myjos(int n,int k){
    return jos(n,k)+1;
}
int main(){
    int n,k;
    cout << "Enter the value of n & k: ";
    cin >> n >> k;
    cout << jos(n,k) << endl;
    cout << myjos(n,k) << endl; // for n to start from 1
    return 0;
}