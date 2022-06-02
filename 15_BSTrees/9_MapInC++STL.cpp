#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,int> m;
    m.insert({10,200});
    m[5]=100;
    m.insert({3,300});
    for(auto &x:m){
        cout << x.first << " " << x.second << endl; 
    }
    cout << "Size: " << m.size() << endl;

    m.at(10)=300; // throws exception if value is not present
    // m.at(9)=1100;
    for(auto it=m.begin();it!=m.end();it++){
        cout << (*it).first << " " << (*it).second << endl;
    }
    m.clear();
    cout << "Size: " << m.size() << endl;
    cout << "Empty: " << (m.empty()?"Yes":"No") << endl;
    return 0;
}