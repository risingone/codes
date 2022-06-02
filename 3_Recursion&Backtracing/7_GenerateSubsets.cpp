/* To generate all possible subsets of a string*/
#include<bits/stdc++.h>
using namespace std;
void subsets(string &str ,string curr, int i){
    if(i==str.length()){ // base case when i become equal to string length
        cout << curr << " ";// we print string and return
        return;
    }                        // There will be 2 cases
    subsets(str,curr,i+1);   // 1: we don't include s[i] element
    subsets(str,curr+str[i],i+1); // 2: we include s[i] element
}
int main(){
    string s;
    cout << "Enter string: ";
    cin >> s;
    subsets(s,"",0);
    return 0;
}