#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30); // 10 20 30
    cout << s.top() << endl; // 10 20
    s.pop();
    cout << s.size() << endl; // 2
    cout << s.top() << endl; // 20

    // to empty the stack
    while(s.empty()==false){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}