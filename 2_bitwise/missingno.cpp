/*Given an array of n number that has values in range[1 .... n+1] Every no. appear exactly once.
 Hence one no is missing. Find the missing number */
 #include<bits/stdc++.h>
 using namespace std;
 int findno(int A[], int n){
     int res=0;
     for(int i=1;i<=n;i++){  // we take xor of numbers till n(n+1 in term of input)
         res ^= i;
     }
     for(int i=0;i<n-1;i++){ // we xor it with array elements,so only missing element will remain
         res ^= A[i];
     }
     return res;
 }
 int main(){
     int n;
     cout << "Enter Array size: ";
     cin >> n;
     int A[n];
     cout << "Enter elements in the array: ";
     for(int i=0;i<n;i++){
         cin >> A[i];
     }
     cout<<findno(A,n+1)<<endl;
     return 0;
 }