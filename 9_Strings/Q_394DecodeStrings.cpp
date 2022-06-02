#include<bits/stdc++.h>
using namespace std;

class Solution {
     string decodeString(string &s,int &i){
         int len=s.length();
         string res;  // to store result
         while(i<len && s[i]!=']'){  // ']' to get out of rec. calls
             if(isdigit(s[i])){
                 int k=0;
                 while(s[i]!='['){          // to store digit
                     k = k*10 + (s[i]-'0');
                     i++;
                 }
                 i++; // to skip '['
                 string str = decodeString(s,i);
                 while(k-->0){ // add str to res k times
                     res += str;
                 }
                 i++; // to skip ']'
             }
             else{          // in case of normal char.
                 res+=s[i];
                 i++;
             }
         }
         return res;
     }
public:
    string decodeString(string s) {
        int i=0;
        return decodeString(s,i);
    }
};

int main(){
    Solution s;
    string str="3[a2[c]]";
    cout << s.decodeString(str) << endl;
    return 0;
}