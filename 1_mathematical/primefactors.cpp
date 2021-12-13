/*To print all the prime factors of a number n ex: 24 = 2,2,2,3*/
#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){  //primality test
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
void primefactor(int n){ //naive solution O(n)
    for(int i=2;i<n;i++){
        if(isprime(i)){
            int x=i;
            while(n%x == 0){
                cout << i <<" ";
                x=x*i;
            }
        }
    }
    cout << endl;
}
void m2_primefactor(int n){ //Efficient solution O(n^0.5)
    if(n<=1) return;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            cout << i <<" ";
            n=n/i;
        }
    }
    if(n>1) // to take care of remaining prime eg: 32-> 2,17(as 17 won't print from above loop)
        cout << n;
    cout << endl;
}
void m3_primefactor(int n){ //most efficient
    if(n<=1) return;
    while(n%2==0){
        cout << 2 << " ";
        n=n/2;
    }
    while(n%3==0){
        cout << 3 << " ";
        n=n/3;
    }
    for(int i=5;i*i<=n;i+=6){
        while(n%i==0){
            cout << i << " ";
            n/=i;
        }
        while(n%(i+2)==0){
            cout << i+2 << " ";
            n/=(i+2);
        }
    }
    if(n>3)
        cout << n;
}
int main(){
    int n;
    cout << "Enter number: ";
    cin>>n;
    primefactor(n); 
    m2_primefactor(n);
    m3_primefactor(n);
    return 0;
}