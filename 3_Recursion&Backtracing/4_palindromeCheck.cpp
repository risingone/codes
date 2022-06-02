/*To check whether the given string is palindrome or not*/
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string &str,int start,int end){
    if(start>=end) return true; 
    return (str[start] == str[end])&&(isPalindrome(str,start+1,end-1));
}
int main(){
    string s;
    cout << "Enter String: ";
    cin >> s;
    if(isPalindrome(s,0,s.length()-1)){
        cout << "String is palindrome";
    }
    else{
        cout << "String is not palindrome";
    }
    return 0;
}