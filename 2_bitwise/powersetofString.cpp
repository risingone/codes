/*To find all the power sets of a string, for string of length n there will be 2^n power sets*/
#include<bits/stdc++.h>
using namespace std;
void printPowerSet(string &str){// ex ab: "",a,b,ab
    int n = str.length();
    int powSize = pow(2,n);
    for(int counter=0; counter<powSize;counter++){  //00="",01="a",10="b",11="ab"
        for(int j=0;j<n;j++){
            if((counter&(1<<j))!=0){ //ex: counter=1 will give str[0],for 2 str[1] etc 
                cout << str[j];
            }
        }
        cout << endl;
    }
}
int main(){
    string s;
    cout << "Enter string: ";
    cin >> s;
    printPowerSet(s);
    return 0;
}