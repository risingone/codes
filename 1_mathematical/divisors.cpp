/*To print divisors of a number n*/
#include<bits/stdc++.h>
using namespace std;
void printDivisor(int n){ //it doesn't print divisors in sorted order O(n^0.5)
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout << i <<" ";
            if(i != (n/i)){           //as we know divisors exist in pair ex: 30- (1,30),(2,15),(3,10),(5,6)
                cout << n/i <<" ";    //also one of the divisor from pair is <= n^0.5
            }
        }
    }
    cout<<endl;
}
void m2_printDivisor(int n){ //it print divisors in sorted order O(n^0.5)
    int i;
    for(i=1;i*i<=n;i++){
        if(n%i==0){
            cout<< i << " "; 
        }
    }
    for(;i>=1;i--){
            if(n%i==0){
                if(i!=(n/i))
                    cout << n/i << " ";
            }
        }
}
int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    printDivisor(n);
    m2_printDivisor(n);
    return 0;
}