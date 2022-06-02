#include<bits/stdc++.h>
using namespace std;

struct Queue{
    int *arr;
    int front,cap,size;
    Queue(int c){
        cap=c;
        size=0;
        front=0;
        arr = new int[cap];
    }
    bool isFull() { return size==cap; }
    bool isEmpty() { return size==0; }
    int getFront(){
        if(isEmpty()) return -1;
        else return front;
    }
    int getRear(){
        if(isEmpty()) return -1;
        else return (front+size-1)%cap;
    }
    void enque(int x){
        if(isFull()) return;
        int rear = getRear();
        rear = (rear+1)%cap;
        arr[rear] = x;
        size++;
    }
    void deque(){
        if(isEmpty()) return;
        front = (front+1)%cap;
        size--;
    }
};

int main(){
    struct Queue q(5);
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    cout << q.getFront() << endl; //0
    cout << q.getRear() << endl; //4
    q.deque();
    q.enque(6);
    cout << q.getFront() << endl;// 1
    cout << q.getRear() << endl;// 0
    return 0;
}