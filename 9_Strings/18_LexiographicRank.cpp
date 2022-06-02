#include<bits/stdc++.h>
using namespace std;
const int CHAR=256;

int fact(int n){
    int res=1;
    for(int i=1;i<=n;i++){
        res *= i;
    }
    return res;
}

int lexRank(string &str){
    int res=1;
    int n=str.length();
    int mul=fact(n); // stores n!
    int count[CHAR] = {0};
    for(int i=0;i<n;i++){ // store freq. of each char.
        count[str[i]]++;
    }
    for(int i=1;i<CHAR;i++){ // pre_sum of freq. to find no. of str. < a pret. str
        count[i] += count[i-1];
    }
    for(int i=0;i<n-1;i++){
        mul = mul/(n-i);
        res = res + count[str[i]-1]*mul; // sum of permutations which are lex. < str
        for(int j=str[i];j<CHAR;j++){
            count[j]--;
        }
    }
    return res; // we don't need to add 1 as we initially took it = 1
}

int main(){
    string str="STRING";
    cout << lexRank(str) << endl;
    return 0;
}