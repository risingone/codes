/* Find Three Numbers (a,b,c)
Such that a!=b!=c!=1, and a*b*c = n
Sol:
   To divide we know we have to take 3 factors of n,
   such that a<b<c
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int a,b,c;
    /*Since we know for x*y=z =) z^0.5 * z^0.5 = z 
      and if one of these decreases other increases, It will be also
      applicable for a*b*c = n, as we take a smallest, we find it < n^1/3*/
    // for a,b,c =) all 3 = n^(1/3), a,b<n^(1/3) and c>n^(1/3), a<n^(1/3) and b,c>n^(1/3)
    for(a=2;a*a*a<=n;a++){
        if(n%a==0) break; // after finding smallest factor of n
    }
    int rem = n/a;
    // now we have to find 2factor i.e smallest factor(>a) of rem
    for(b=a+1;b*b<=rem;b++){
        if(rem%b==0){
            c=rem/b;
            if(b>=c) c=0; // as c can't be = to b or a
            break;
        }
    }
    if(a*b*c == n){
        cout << "YES: " << a << "*" << b << "*" << c << " = " << n << endl;
    } else{
         cout << "NOT POSSIBLE!" << endl;
    }
    return 0;
}