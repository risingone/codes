/*To divide n length rope into maximum different parts with combined length = n and
 parts length will be from a,b&c */
 #include<bits/stdc++.h>
 using namespace std;
 int Max(int a, int b, int c){
     return max(max(a,b),max(b,c));
 }
 int maxPieces(int n, int &a, int &b,int &c){
     if(n==0) return 0; // base case when we find soln
     if(n<0) return -1; // base case when soln is not possible in this component
     int res = Max(maxPieces(n-a,a,b,c),maxPieces(n-b,a,b,c),maxPieces(n-c,a,b,c));
     if(res==-1) return -1; // -1 will be returned when no solution is possible
     return res+1; // it will give total no. of components(soln)
 }
 int main(){
     int n,a,b,c;
     cout << "Enter string length: ";
     cin >> n;
     cout << "Enter values of a, b & c: ";
     cin >> a >> b >> c;
     cout << maxPieces(n,a,b,c);
 }