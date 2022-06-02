#include<bits/stdc++.h>
using namespace std;

string findLongestSubstring(string &str){
    int freq[26] = {0};
    int begin=0,end=0;
    for(int low=0,high=0;high<str.length();high++){
        if(freq[str[high]-'a']){
            while(str[low]!=str[high]){
                freq[str[low]-'a']=0;
                low++;
            }
            low++;
        } else{
            freq[str[high]-'a']=1;
            if((end-begin)<(high-low)){
                begin=low;
                end=high;
            }
        }
    }
    return str.substr(begin,end-begin+1);
}

int main(){
    string str="abcebadc";
    cout << findLongestSubstring(str) << endl;
    return 0;
}