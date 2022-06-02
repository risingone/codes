#include<bits/stdc++.h>
using namespace std;

void recSol(int arr[],int& n,string str,int i,unordered_map<int,string>& ump,vector<string>& res){
    if(str.length()==n){
        res.push_back(str);
        return;
    }
    string currEle=ump[arr[i]];
    for(int j=0;j<currEle.length();j++){
        str.push_back(currEle[j]);
        recSol(arr,n,str,i+1,ump,res);
        str.pop_back();             // for backtracking
    }
    return;
}

vector<string> posComb(int arr[],int n){
    vector<string> res;
    unordered_map<int,string> ump;
    ump.insert({2,"abc"});
    ump.insert({3,"def"});
    ump.insert({4,"ghi"});
    ump.insert({5,"jkl"});
    ump.insert({6,"mno"});
    ump.insert({7,"pqrs"});
    ump.insert({8,"tuv"});
    ump.insert({9,"wxyz"});
    recSol(arr,n,"",0,ump,res);
    return res;
}

int main(){
    int a[] = {2,3,4};
    int n=3;
    vector<string> ans = posComb(a,n);
    for(auto& it: ans){
        cout << it << " ";
    }
    return 0;
}