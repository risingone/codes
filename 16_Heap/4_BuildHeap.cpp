#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    int *arr;
    int size;
    int capacity;
    public:
    MinHeap(int c){
        size=0;
        capacity=c;
        arr = new int[capacity];
    }
    // random insert to check build heap function 
    void ranInsert(int x){
        if(size==capacity) return;
        arr[size]=x;
        size++;
    }
    void show(){
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int left(int i) { return 2*i + 1; }
    int right(int i) { return 2*i + 1; }
    int parent(int i) { return (i-1)/2; }
    
    void minHeapify(int i){
        int smallest=i;
        int lt=left(i),rt=right(i);
        if(lt<size && arr[lt]<arr[smallest]) smallest=lt;
        if(rt<size && arr[rt]<arr[smallest]) smallest=rt;
        if(smallest!=i){
            swap(arr[i],arr[smallest]);
            minHeapify(smallest);
        }
    }
    void buildHeap(){
        for(int i=(size-2)/2;i>=0;i--){ // since index of last node is (Size-1) so we start from its parent
            minHeapify(i);
        }
    }
};

int main(){
    MinHeap h(11);
    // inserting nodes randomly
    h.ranInsert(10);
    h.ranInsert(5);
    h.ranInsert(20);
    h.ranInsert(2);
    h.ranInsert(4);
    h.ranInsert(8);
    h.show();
    h.buildHeap();
    h.show();
    return 0;
}