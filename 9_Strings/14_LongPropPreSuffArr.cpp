#include<bits/stdc++.h>
using namespace std;

int longPropPreSuff(string str,int n){
    for(int len=n-1;len>0;len--){ // traverse the loop from len=n-1 -> 1
        bool flag=true;           // to check for part. len if prop. pre==suff
        for(int i=0;i<len;i++){
            if(str[i]!=str[n-len+i]){ // to match char's for a part. len
                flag=false;
            }
        }
        if(flag) return len;      // if flag don't change return len.
    }
    return 0; // when len=0 return 0
}
// naive approach: O(n^3)
void fillLPS(string str, int lps[]){
    for(int i=0;i<str.length();i++){ // fill lps arr.
        lps[i] = longPropPreSuff(str,i+1);
    }
}

// efficient approach: O(n)
void fillLPS1(string str1,int lps1[]){
    int n1=str1.length(),len=0;
    lps1[0]=0;
    int i=1;
    while(i<n1){                   // in it we will keep len = prev ele. lps val.
        if(str1[i]==str1[len]){    // case 1: when ith and len. char match
            len++;
            lps1[i]=len;           // lps val. of currr ind. = prev. + 1
            i++;
        }
        else{                      // case 2: when they don't match
            if(len==0){            // 2(a) -> if(len==0) =) for prev ind. lps val. was 0
                lps1[i]=0;         //         keep lps val. 0 and inc. i
                i++;
            }
            else{                  // 2(b) -> if prev. ind. had some lps val. >0
                len=lps1[len-1];   // make len = lps. val. of prev. ele and
            }                      // traverse rec. until you end up in 1 or 2(a)
        }
    }
}

int main(){
    string str = "ababab";
    int n=str.length();
    int lps[n];
    fillLPS(str,lps);
    for(int i=0;i<n;i++){
        cout << lps[i] <<" ";
    }
    cout << endl;
    string str1 = "AAABAAAAC";
    int n1=str1.length();
    int lps1[n1];
    fillLPS1(str1, lps1);
    for(int i=0;i<n1;i++){
        cout << lps1[i] << " ";
    }
    return 0;
}