/*To print first m N-bonacci numbers.
e.g: i/p: N=3,m=5
     o/p: 0 0 1 1 2 4 7 13
     i/p: N=4,m=10
     o/p: 0 0 0 1 1 2 4 8 15 29*/
#include<bits/stdc++.h>
using namespace std;
void printNbonacci(int N,int m){
    int arr[m];   // to store first m elements
    for(int i=0;i<N-1;i++){
        arr[i]=0; // first N-1 terms will be zero
    }
    arr[N-1]=1;   // & Nth term will be 1
    int sum=1;    // their sum will also be 1
    for(int i=0;i<m-N+1;i++){ // for remaining m-N elements traverse
        arr[N+i]=sum;         // store sum in N+i th index element
        sum += (arr[N+i]-arr[i]);// update sum
    }
    for(int i=0;i<m;i++){ // print m elements
        cout << arr[i] << " ";
    }
}
int main(){
    int N=3,m=8;
    printNbonacci(N,m);
}