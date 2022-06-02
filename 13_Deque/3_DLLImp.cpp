#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next,*prev;
    Node(){}
    Node(int x){
        data=x;
        next = prev =NULL;
    }
};

struct Deque{
    Node *front,*rear;
    int size;
    Deque(){
        size=0;
        front=NULL;
        rear=NULL;
    }
    bool isEmpty(){
        return front==NULL;
    }
    void insertFront(int x){
        Node *temp = new Node(x);
        if(isEmpty()){
            front = rear = temp;
            size++; 
            return;
        }
        temp->next = front;
        front->prev = temp;
        front = temp;
        size++;
    }
    void deleteFront(){
        if(isEmpty()) return;
        Node *temp = front;
        size--;
        front = front->next;
        delete temp;
        if(front==NULL){
            rear==NULL;
            return;
        }
        front->prev=NULL;
    }
    int getFront(){
        if(isEmpty()) return -1;
        return front->data;
    }
    void insertRear(int x){
        Node *temp = new Node(x);
        if(isEmpty()){
            front = rear = temp;
            size++; 
            return;
        }
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
        size++;
    }
    void deleteRear(){
        if(isEmpty()) return;
        Node *temp=rear;
        rear=rear->prev;
        size--;
        delete temp;
        if(rear==NULL){
            front=NULL;
            return;
        }
        rear->next=NULL;
    }
    int getRear(){
        if(isEmpty()) return -1;
        return rear->data;
    }
};

int main(){
    Deque d;
    d.insertFront(10);
    d.insertRear(20);  // 10 20
    d.insertRear(30);  // 10 20 30
    cout << d.getFront() << endl;
    cout << d.getRear() << endl;
    d.deleteFront();
    d.deleteRear(); // 20
    cout << d.getFront() << endl;
    cout << d.getRear() << endl;
    d.deleteFront();
    d.deleteRear();
    cout << d.getFront() << endl;
    cout << d.getRear() << endl;
    d.insertRear(40);
    cout << d.getFront() << endl;
    cout << d.getRear() << endl;
    return 0;
}