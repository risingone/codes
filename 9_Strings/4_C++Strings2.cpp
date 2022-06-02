#include<bits/stdc++.h>
using namespace std;

int main(){
    // M-1 Getting input from user
    // string str;
    // cout << "Enter your name: ";
    // cin >> str; // it won't take " "
    // cout << "\n Your name is " << str;

    // M-2
    string str1;
    cout << "Enter your name: ";
    getline(cin,str1); // it can take space too,
    // it finishes at '\n'
    // we can even specify terminating char as 3 arg.
    cout << "\n Your name is " << str1;
    cout << endl;
    
    // print as arr using for loops
    for(int i=0;i<str1.length();i++){
        cout << str1[i];
    }
    cout << endl;
    for(char x: str1){
        cout << x;
    }
    return 0;
}