#include<bits/stdc++.h>
using namespace std;
// LC 438
vector<int> getCount(string &s,string &p){
    vector<int> vec;
    unordered_map<int,int> fq;
    for(char &c: p){
        fq[c]++;
    }
    int count=fq.size(),k=p.length(),i=0,j=0;
    while(j<s.length()){
        if(fq.find(s[j])!=fq.end()){
            fq[s[j]]--;
            if(fq[s[j]]==0) count--;
        }
        if((j-i+1)<k) j++;
        else if((j-i+1)==k){
            if(count==0) vec.push_back(i);
            if(fq.find(s[i])!=fq.end()){
                fq[s[i]]++;
                if(fq[s[i]]==1) count++;
            }
            i++;
            j++;
        }
    }
    return vec;
}

int main(){
    // find no. of occ. of p's anagram in s
    string s="aabaabaa";// 4
    string p="aaba";
    vector<int> res = getCount(s,p);
    for(auto &it: res){
        cout << it << " ";
    }
    return 0;
}