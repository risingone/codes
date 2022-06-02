#include<bits/stdc++.h>
using namespace std;

// M-1: using auxilary stack
// struct MyStack{
//     stack<int> ms;
//     stack<int> as;
//     void push(int x){
//         if(as.empty() || x<=as.top()){
//             as.push(x);
//         }
//         ms.push(x);
//     }
//     int pop(){
//         int tp = ms.top();
//         ms.pop();
//         if(tp==as.top()){
//             as.pop();
//         }
//         return tp;
//     }
//     int top(){
//         return ms.top();
//     }
//     int min(){
//         return as.top();
//     }
// };

// M-2: For +ve elements only TC: O(n) SC: O(1)
// struct MyStack{
//     int min;
//     stack<int> s;
//     void push(int x){
//         if(s.empty()){
//             min = x;
//             s.push(x);
//         } else if(x<=min){
//             s.push(x-min);
//             min=x;
//         } else{
//             s.push(x);
//         }
//     }
//     int pop(){
//         int t = s.top();
//         s.pop();
//         if(t<=0){
//             int res=min;
//             min=min-t;
//             return res;
//         }
//         else{
//             return t;
//         }
//     }
//     int peek(){
//         int t=s.top();
//         return (t<=0)?min:t;
//     }
//     int getMin(){
//         return min;
//     }
// };

// M-3: handle's -ve too
struct MyStack{
    int min;
    stack<int> s;
    void push(int x){
        if(s.empty()){
            min = x;
            s.push(x);
        } else if(x<=min){
            s.push(2*x-min);
            min=x;
        } else{
            s.push(x);
        }
    }
    int pop(){
        int t = s.top();
        s.pop();
        if(t<=min){
            int res=min;
            min=2*min-t;
            return res;
        }
        else{
            return t;
        }
    }
    int peek(){
        int t=s.top();
        return (t<=min)?min:t;
    }
    int getMin(){
        return min;
    }
};

int main(){
    MyStack s;
    s.push(5);
    s.push(10);
    s.push(20);
    s.push(-2);
    s.push(-6);
    s.push(4);
    cout << s.getMin() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.getMin() << endl;
    s.push(2);
    cout << s.pop() << endl;
    s.push(1);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}