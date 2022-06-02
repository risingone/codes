#include<bits/stdc++.h>
using namespace std;

// M-1: modify push operation
struct Stack{
    queue<int> q1,q2;
    int top(){
        return q1.front();
    }
    int size(){ return q1.size(); }
    void pop(){ q1.pop(); }
    void push(int x){ 
        // place all items of q1 into q2
        while(!q1.empty()){          // 1 2     <-  5
            q2.push(q1.front());     // 1 2
            q1.pop();
        }
        q1.push(x);                  // 5 
        while(!q2.empty()){          // 5 1 2
            q1.push(q2.front());
            q2.pop();
        }
    }
};

//M-2: modify pop operation
// struct Stack{
//     queue<int> q1,q2;
//     int top(){
//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         while(q2.size()!=1){
//             q1.push(q2.front());
//             q2.pop();
//         }
//         int res=q2.front();
//         q1.push(q2.front());
//         q2.pop();
//         return res;
//     }
//     int size(){ return q1.size(); }
//     void pop(){
//         while(q1.size()!=1){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         q1.pop();
//         while(!q2.empty()){
//             q1.push(q2.front());
//             q2.pop();
//         }
//     }
//     void push(int x){ 
//         q1.push(x);
//     }
// };

int main(){
    Stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    cout << s.size() << endl; // 3
    cout << s.top() << endl; // 3
    s.pop();
    cout << s.top() << endl; // 4
    return 0;
}