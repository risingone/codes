#include<bits/stdc++.h>
using namespace std;

struct MyStack{
    int *arr;
    int cap;
    int top;
    // to create stack of capacity c
    MyStack(int c){
        cap = c;
        arr = new int[cap];
        top=-1;
    }
    void push(int x){
        if(top == cap-1){
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack Underflow" << endl;
            return INT_MAX;
        }
        int res = arr[top];
        top--;
        return res;
    }
    int peek(){
        return arr[top];
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        return top==-1;
    }
};

int main(){
    struct MyStack s(5);
    cout << s.pop() << endl;
    s.push(5);
    s.push(10);
    s.push(20); // 5 10 20
    cout << s.pop() << endl; // 5 10
    cout << s.peek() << endl;
    cout << s.size() << endl;
    return 0;
}