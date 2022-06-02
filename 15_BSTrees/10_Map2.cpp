#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int, string> m;
    m.insert({5,"gfg"});
    m.insert({2,"ide"});
    m.insert({1,"practice"});

    if(m.find(5)==m.end()){
        cout << "Not Found" << endl;
    }
    else{
        cout << "Found" << endl;
    }
    if(m.count(2)==0){
        cout << "Not Found" << endl;
    }
    else{
        cout << "Found" << endl;
    }

    // lower_bound
    auto it = m.lower_bound(5);
    if(it!=m.end()){
        cout << (*it).first << " " << (*it).second << endl;
    } else{
        cout << "No Equal or Greater Value" << endl;
    }

    // upper_bound
    auto it2 = m.upper_bound(5);
    if(it2!=m.end()){
        cout << (*it2).first << " " << (*it2).second << endl;
    } else{
        cout << "No Equal or Greater Value" << endl;
    }

    m.erase(5);
    cout << "Size: " << m.size() << endl;

    m.erase(m.find(2),m.end());
    cout << "Size: " << m.size() << endl;
    return 0;
}