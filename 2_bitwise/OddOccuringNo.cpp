/*Find the only odd occuring number in the array*/
#include<bits/stdc++.h>
using namespace std;
void naive(int A[],int n){  // it will be O(n^2)
    for(int i=0;i<n;i++){
        int count =0;
        for(int j=0;j<n;j++){
            if(A[j]==A[i]) count++;
        }
        if((count&1)==1){
            cout << A[i] << endl;
        }
    }
}
int findOdd(int A[],int n){ // This solution uses xor operator O(n)
    int res=0;              // as a^a=0 and 0^a=a
    for(int i=0;i<n;i++){   // so numbers occuring even no of times form 0
        res ^= A[i];        // only number occuring odd number of times remains
    }
    return res;
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
    cout << findOdd(A,n) << endl;
    return 0;
}