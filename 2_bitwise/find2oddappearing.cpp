#include<bits/stdc++.h>
using namespace std;
void naive(int A[],int n){ // naive approach O(n^2)
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(A[i]==A[j]) count++;
        }
        if((count&1==1)){
            cout << A[i] << " ";
        }
    }
    cout << endl;
}
void oddAppearing(int A[], int n){ //using XOR O(n)
    int XOR=0,res1=0,res2=0;
    for(int i=0;i<n;i++){ // it will give odd1^odd2 as other no. occuring even times cancel out
        XOR ^= A[i];
    }
    int sn = XOR&~(XOR-1); // it will give a number in which LSB(different for odd1 & odd2) is set rest all are 0
    for(int i=0;i<n;i++){
        if((A[i]&sn)!=0) res1 ^= A[i]; // it will make a group of odd1 type numbers
        else
        res2 ^= A[i]; // it will make a group of odd2 type numbers
    }
    cout << res1 << " " << res2;
}
int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int A[n];
    cout << "Enter elements in array: ";
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    naive(A,n);
    oddAppearing(A,n);
    return 0;
}