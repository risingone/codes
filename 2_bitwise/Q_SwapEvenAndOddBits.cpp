#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned int n=23;
    // A->1010 5->0101
    unsigned int e=n&0xAAAAAAAA; //only even bits remains, odd bits will be masked
    unsigned int o=n&0x55555555;
    e=e>>1; // even bits go at odd's places
    o=o<<1;// and vice versa
    e=e|o; // or them to get swapped bits
    cout << e << endl;
    return 0;
}