#include<bits/stdc++.h>
using namespace std;

struct Key {
    int freq;
    char ch;
    bool operator< (const Key &k) const
    {
        return freq < k.freq;
    }
};

// TC: nlog(26) SC: O(26)=) O(1)
string rearrangeString(string str){
    int n=str.length();
    int count[26] = {0};
    // to store freq. of each char
    for(int i=0;i<n;i++){
        count[str[i]-'a']++;
    }
    priority_queue< Key > pq;
    for(char c = 'a';c<='z';c++){
        if(count[c-'a']) pq.push( Key{ count[c-'a'], c} );
    }
    str="";
    Key prev {-1,'#'};
    while(!pq.empty()){
        Key k = pq.top();
        pq.pop();
        str += k.ch;
        if(prev.freq > 0) pq.push(prev);
        k.freq--;
        prev = k;
    }
    if(n != str.length()) return "-1";
    else return str;
}

int main(){
    string s="geekforgeeks";
    string res=rearrangeString(s);
    cout << s << " gives -> " << res << endl;
    return 0;
}