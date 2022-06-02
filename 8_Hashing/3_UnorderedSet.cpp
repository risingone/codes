#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    // for it almost all methods take O(1) time
    unordered_set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);
    for(int x: s){ // for each loop
        cout << x << " ";
    }
    cout << endl;
    for(auto it=s.begin();it!=s.end();it++){ //printing using iterators
        cout << *it << " ";
    }
    cout << endl;
    cout << s.size() << endl; // size method
    // s.clear();                // clear method
    // cout << s.size() << endl;

    if(s.find(15)==s.end()){  // find method
        cout << "Not Found" << endl;
    }
    else{
        cout << "Found " << *(s.find(15)) << endl;
    }
    // count method
    if(s.count(15)) //it gives 1 if element is present
        cout << "Found " << endl;
    else
        cout << "Not Found" << endl;
    
    s.erase(15); // erase method to remove an element
    cout << s.size() << endl;
    auto it = s.find(10); // it iterator to element 10
    s.erase(it); // removing element using an iterator to the element
    cout << s.size() << endl;
    s.erase(s.begin(),s.end()); // works similar to clear method
    cout << s.size() << endl;
    return 0;
}