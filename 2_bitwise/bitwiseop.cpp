#include<bits/stdc++.h>
using namespace std;
int main(){
    /*to check whether number is odd or even*/
    // int a;   
    // cout << "enter number: " << endl;
    // cin >> a;
    // if((a&1) == 1){
    //     cout << "number is odd\n" << endl;
    // }
    // else{
    //     cout << "number is even\n" << endl;
    // }

    /*to swap 2 numbers*/
    // int a,b;  
    // cout << "enter numbers to swap: " << endl;
    // cin >> a >> b;
    // a=a^b;
    // b=a^b;
    // a=a^b;
    // cout << a << " " << b << endl;
     
    /*to find number of bits to be changed to convert a to b*/
    int a,b,n,count=0;  
    cout << "enter numbers: ";
    cin >> a >> b;
    n=a^b;// now question is to find number of bits which are 1 in c as c will give the bits to be changed
    // while(n != 0){ //m-1 (log2 n + 1) = no. of bits in n
    //     if(n&1 == 1){  // O(log2 n)
    //         count++;
    //     }
    //     n= n>>1;
    // }
    while(n != 0){
        n = n&(n-1);
        count++;
    }
    cout << count << endl;
    return 0;
}