#include<iostream>
#include<string>
using namespace std;

int main(){
    // 1 concat, length, substr and find
    string str = "geeksforgeeks";
    cout << str.length() << " ";
    str = str + "xyz";
    cout << str << " ";
    cout << str.substr(2,2) << " ";
    cout << str.find("eek") << endl;
    // 2 < and ==
    string s1 = "abc";
    string s2 = "bcd";
    if(s1==s2){
        cout << "Same";
    }
    else if(s1<s2){
        cout << "Smaller";
    } 
    else{
        cout << "Greater";
    }
    return 0;
}