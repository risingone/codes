#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

struct Queue{
    Node *front,*rear;
    int size;
    Queue(){ front=NULL; rear=NULL; size=0; }
    void enque(int x){
        Node* temp = new Node(x);
        size++;
        if(front==NULL){
            front=rear=temp;
            return;
        }
        rear->next = temp;
        rear=temp;
    }
    void deque(){
        if(front==NULL) return;
        size--;
        Node *temp=front;
        front=front->next;
        if(front==NULL) rear=NULL;
        delete temp;
    }
    int getSize(){
        if(front==NULL) return 0;
        else return size;
    }
};

int main(){
    Queue q;
    q.enque(2);
    q.enque(4);
    q.enque(5);
    q.enque(6);
    q.deque();
    cout << q.getSize() << endl;
    return 0;
}