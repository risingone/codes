#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq = {10,20,30};
    dq.push_front(5);
    dq.push_back(50);
    // don't run on vs code
    // auto it = dq.begin();
    // it++;
    // dq.insert(it, 8); // 5 8 10 20 30 50 
    for(auto &x: dq){
        cout << x << " ";
    }
    cout << endl;
    dq.pop_front();
    dq.pop_back();
    cout << dq.front() << " " << dq.back() << endl;
    cout << dq.size() << endl;
    return 0;
}