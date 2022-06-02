#include<bits/stdc++.h>
using namespace std;

char getMaxOccuringChar(string &str) // to find max occ. char and incase of multiple
    {                                // ans return lexiographically < one.
        // Your code here
        int n=str.length(),res=0,ind=0; // we store freq. and ascii val. of resulting char.
        int count[256]={0};
        for(int i=0;i<n;i++){
            count[str[i]]++;                 // update freq.
            if(count[str[i]]>=res){
                if(count[str[i]]==res){      // in case of = freq.
                    ind=min(ind,(int)str[i]);// store < ascii val. in ind(as it is lex. < char) 
                }else{
                    res=count[str[i]];         // else update freq. and ascii val.
                    ind=str[i];
                }
                // cout << char(ind) << endl;
            }
        }
        return char(ind);
    }

int main(){
    string str="flipkart";
    cout << getMaxOccuringChar(str) << endl;
    return 0;
}