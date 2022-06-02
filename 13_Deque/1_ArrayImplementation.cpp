#include<bits/stdc++.h>
using namespace std;

struct Deque{
    int *arr;
    int cap,size;
    Deque(int c){
        cap=c;
        arr = new int[cap];
        size=0;
    }
    bool isFull() { return size==cap; }
    bool isEmpty() { return size==0; }
    void insertRear(int x){
        if(isFull()) return;
        arr[size]=x;
        size++;
    }
    void deleteRear(){
        if(isEmpty()) return;
        size--;
    }
    int getRear(){
        if(isEmpty()) return -1;
        return arr[size-1];
    }
    void insertFront(int x){
        if(isFull()) return;
        for(int i=size-1;i>=0;i--){
            arr[i+1] = arr[i];
        }
        arr[0] = x;
        size++;
    }
    void deleteFront(){
        if(isEmpty()) return;
        for(int i=0;i<size-1;i++){
            arr[i]=arr[i+1];
        }
        size--;
    }
    int getFront(){
        if(isEmpty()) return -1;
        return arr[0];
    }
};

int main(){
    Deque d(5);
    d.insertRear(10);
    d.insertFront(20); // 20 10
    d.insertRear(30);  // 20 10 30
    d.insertFront(40); // 40 20 10 30
    cout << d.getFront() << endl;
    cout << d.getRear() << endl;
    return 0;
}