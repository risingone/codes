/*To count no.of trailing zeros in factorial of a number n*/
#include<bits/stdc++.h>
using namespace std;
int countTrailingZeros(int n){ // as 10=2*5 , so we try to find no. of 5 as it will be less than 2
    int res=0;                 // 1,2,3,4,5......25(5*5)......125(5*5*5)
    for(int i=5;i<=n;i=i*5){
        res = res + n/i;
    }
    return res;
}
int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << countTrailingZeros(n);
}