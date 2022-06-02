#include<bits/stdc++.h>
using namespace std;

int main(){
    // Stack
    cout << "Stack: " << endl;
    stack<int> st; // lifo ds
    st.push(2);
    st.push(4);
    st.push(3);
    st.push(1);

    cout << st.top() << endl; // prints 1
    st.pop(); // deletes the last inserted element
    cout << st.top() << endl; // prints 3
    st.pop();
    cout << st.top() << endl; // prints 4

    bool flag = st.empty(); // returns true if stack is empty
    // cout << flag << endl;

    cout << st.size() << endl; // returns the size of stack 

    // delete the entire stack
    while(!st.empty()){
        st.pop();
    }
    // cout << st.empty() << endl;
    
    stack<int> st1;
    if(!st.empty()){
        cout << st1.top() << endl; // throw error otherwise
    }
     // queue
    cout << "Queue: " << endl;
    queue<int> q;  // fifo operation ds
    q.push(1);
    q.push(5);
    q.push(3);
    q.push(6);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << endl;
    while(!q.empty()){
        q.pop();
    }
    cout << q.size() << endl;
    // priority_queue
    cout << "priority_queue" << endl;
    priority_queue<int> pq;
    pq.push(1);
    pq.push(5);
    pq.push(2);
    pq.push(6);

    cout << pq.top() << endl; // 6
    pq.pop();
    cout << pq.top() << endl; // 5
    cout << pq.size() << endl;
    return 0;
}