#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    int* arr;
    int size;
    int capacity;
    public:
    // constuctor to make heap of capacity=c
    MinHeap(int c){
        size=0;
        capacity=c;
        arr=new int[c];
    }
    // to get left,right and parent's index
    int left(int i){ return (2*i + 1); }
    int right(int i){ return (2*i + 2); }
    int parent(int i){ return (i-1)/2; }

    void insert(int x){
        if(size == capacity) return;
        arr[size]=x;
        for(int i=size;i!=0 && arr[parent(i)]>arr[i];){
            swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }
        size++;
    }
    // to check
    void show(){
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    MinHeap h(11);
    h.insert(3);  
    h.insert(2);     
    h.insert(15);   
    h.insert(20);
    /*     3            2             1
         /    ->      /  \    ->    /   \
        2            3    15       2     15 
                    /             / \
                  20             20  3
    */
    h.show();
    h.insert(1);
    h.show();
    return 0;
}