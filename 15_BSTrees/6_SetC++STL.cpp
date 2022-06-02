#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(10); // there are no duplicates in set
    for(int x: s){
        cout << x << " ";
    }
    cout << endl;
    for(set<int>::iterator it=s.begin();it!=s.end();it++){ // that's why we use auto
        cout << *it << " ";
    }
    cout << endl;
    for(auto it=s.rbegin();it!=s.rend();it++){
        cout << *it << " ";
    }
    auto it = s.find(10);
    if(it==s.end()){
        cout << "\nNot Found\n";
    } else{
        cout << "\nFound\n";
    }
    cout << s.size() << endl;
    cout << s.count(5) << endl; // can be used in place of find function
    s.clear(); // to clear the set
    cout << s.size() << endl;
    
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(7);  // 5 7 10 20
    // s.erase(5); // erase 5 from the set
    auto it2 = s.find(7);
    s.erase(it2,s.end()); // delete all elements from 7 to end of set
    for(int x: s){ // 5
        cout << x << " ";
    }
    cout << endl;
    return 0;
}