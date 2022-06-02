#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    // Like unordered_set in it also, almost all functions are O(1)
    unordered_map<string, int> m;
    m["gfg"] = 20; // we can add pairs like this
    m["ide"] = 30; // and we can also modify value associated with key
    m.insert({"courses", 15}); // we can also use insert method to add (key,value) pair
    
    for(auto x: m){ // printing key->value pair
        cout << x.first << " " << x.second << endl;
    }

    // using find method
    auto it = m.find("ide");
    if(it != m.end())
        cout << "Found " << it->second << endl;
    else
        cout << "Not Found " << endl;

    // using count method which can be used like find
    if(m.count("gfg")>0)
        cout << "Found " << endl;
    else
        cout << "Not Found" << endl;

    cout << m.size() << endl;
    m.erase("gfg");
    m.erase(m.begin());
    cout << m.size() << endl;

     for(auto it=m.begin(); it!=m.end(); it++){ // printing
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}