#include<bits/stdc++.h>
using namespace std;

// M-1 Iterative
void reverse(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

// M-2 Recursive
void recRev(queue<int> &q){
    if(q.empty()) return;
    int x=q.front();
    q.pop();
    reverse(q);
    q.push(x);
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(5);
    q.push(15);
    q.push(20);
    cout << q.front() << endl; // 10 5 15 20
    // reverse(q); // 20 15 5 10
    // while(!q.empty()){
    //     cout << q.front() << endl; 
    //     q.pop();
    // }
    recRev(q);
    while(!q.empty()){
        cout << q.front() << endl; 
        q.pop();
    }
    return 0;
}