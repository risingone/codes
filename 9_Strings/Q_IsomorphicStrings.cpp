#include<bits/stdc++.h>
using namespace std;
const int MAX_CHARS=256;

class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string &str1, string &str2)
    {
        if(str1.length()!=str2.length()) return false;
        int n=str1.length();
        int count1[MAX_CHARS]={0};// to store mapping str1->str2
        int count2[MAX_CHARS]={0};//  str2->str1
        for(int i=0;i<n;i++){
            if(!count1[str1[i]] && !count2[str2[i]]){ //if it is 1 occ. for both 
                count1[str1[i]]=str2[i];              // store mapping
                count2[str2[i]]=str1[i];
            }
            else{                                     // else check if mapping is proper or not
                if(count1[str1[i]]!=str2[i] || count2[str2[i]]!=str1[i]) return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    string str1="pijthbsfy";
    string str2="fvladzpbf";
    cout << s.areIsomorphic(str1,str2) << endl;
    return 0;
}