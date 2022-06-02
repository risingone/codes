#include<bits/stdc++.h>
using namespace std;
void TOH(int n,char A,char B,char C){
    if(n==1){ // base case when bottom most piece is transferred
        cout << "Move 1 from " << A <<" to " << C << endl;
        return;
    }
    TOH(n-1,A,C,B); // first we transer all n-1 pieces above nth piece to tower B via C
    cout << "Move " << n <<" from "<<A <<" to " << C << endl; // then  nth piece to tower C 
    TOH(n-1,B,A,C); // then all remaining n-1 pieces to tower C via tower A
}
int main(){
    int n;
    cout << "Enter n: ";
    cin>>n;
    TOH(n,'A','B','C');
    return 0;
}