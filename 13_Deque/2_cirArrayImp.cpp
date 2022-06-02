#include<bits/stdc++.h>
using namespace std;

struct Deque{
    int *arr;
    int front, cap, size;
    Deque(int c){
        arr = new int[c];
        cap=c;
        front=0;
        size=0;
    }
    bool isEmpty(){ return size==0; }
    bool isFull(){ return size==cap; }
    void insertFront(int x){
        if(isFull()) return;
        front = (front-1+cap)%cap;
        arr[front] = x;
        size++;
    }
    void deleteFront(){
        if(isEmpty()) return;
        front = (front+1)%cap;
        size--;
    }
    int getFront(){
        if(isEmpty()) return -1;
        return arr[front];
    }
    void insertRear(int x){
        if(isFull()) return;
        int new_rear = (front+size)%cap;
        arr[new_rear] = x;
        size++;
    }
    void deleteRear(){
        if(isEmpty()) return;
        size--;
    }
    int getRear(){
        if(isEmpty()) return -1;
        return arr[(front+size-1)%cap];
    }
};

int main(){
    Deque d(5);
    d.insertFront(10);
    d.insertRear(20);  // 10 20
    d.insertRear(30);  // 10 20 30
    cout << d.getFront() << endl;
    cout << d.getRear() << endl;
    d.deleteFront();
    d.deleteRear(); // 20
    cout << d.getFront() << endl;
    cout << d.getRear() << endl;
    return 0;
}