#include<bits/stdc++.h>
using namespace std;

struct MyStack{
    vector<int> v;
    void push(int x){
        v.push_back(x);
    }
    int pop(){
        int res = v.back();
        v.pop_back();
        return res;
    }
    int size(){
        return v.size();
    }
    bool isEmpty(){
        return v.empty();
    }
    int peek(){
        return v.back();
    }
};

int main(){
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30); // 10 20 30
    cout << s.pop() << endl; // 10 20
    cout << s.peek() << endl;
    cout << s.size() << endl;
    return 0;
}