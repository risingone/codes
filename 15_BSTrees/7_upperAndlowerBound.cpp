#include<bits/stdc++.h>
using namespace std;

int main(){
    // lower_bound(>=)  and  upper_bound(>)
    set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(20); // 5 10 20
    auto it = s.lower_bound(5);
    if(it != s.end()){
        cout << *it << endl;
    } else{
        cout << "Given element is greater than the largest" << endl;
    }
    auto it2 = s.upper_bound(5);
    if(it2 != s.end()){
        cout << *it2 << endl;
    } else{
        cout << "Given element is greater than the largest" << endl;
    }
}