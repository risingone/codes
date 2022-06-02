#include<bits/stdc++.h>
using namespace std;
// O(T * sqrt(n))
bool checkPrime(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            cnt++;
            if((n/i) != i){
                cnt++;
            }
        }
    }
    if(cnt==2) return true;
    return false;
}

// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         if(checkPrime(n)){
//             cout << "Yes" << endl; 
//         } else{
//             cout << "No" << endl;
//         }
//     }
// }

// TC: O(n log(log n)) almost O(n)
int N = 1000000;
bool sieve[1000001];
// TC: O(nlog(logn))
void createSieve(){
    for(int i=2;i<=N;i++){
        sieve[i] = true;
    }
    for(int i=2;i*i<=N;i++){
        if(sieve[i] == true) {
            for(int j=i*i;j<=N;j+=i){
                sieve[j]=false;
            }
        }
    }
}

int main() {
    createSieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(sieve[n]==true){
            cout << " Yes " << endl;
        } else{
            cout << " No " << endl;
        }
    }
    return 0;
}