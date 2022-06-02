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

    int left(int i){ return (2*i + 1); }
    int right(int i){ return (2*i + 2); }
    int parent(int i){ return (i-1)/2; }
    void insert(int x){
        arr[size]=x;
        for(int i=size;i!=0 && arr[parent(i)]>arr[i];){
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
        size++;
    }
    // heapify
    void minHeapify(int i){
        int smallest=i;
        int lt=left(i),rt=right(i);
        if(lt<size && arr[lt]<arr[smallest]) smallest=lt;
        if(rt<size && arr[rt]<arr[smallest]) smallest=rt;
        if(i!=smallest){
            swap(arr[i],arr[smallest]);
            minHeapify(smallest);
        }
    }
    // extract min
    int extractMin(){
        if(size==0) return INT_MAX;
        if(size==1){
            size--;
            return arr[0];
        }
        size--;
        swap(arr[0],arr[size]);
        minHeapify(0);
        return arr[size];
    }
    // decreaseKey
    void decreaseKey(int i,int x){
        if(i>=size) return; // not to insert at >=size
        arr[i] = x;
        while(i!=0 && arr[i]<arr[parent(i)]){
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
    }
    // deleteKey
    void deleteKey(int i){
        decreaseKey(i,INT_MIN);
        extractMin();
    }
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
    h.insert(2);     // 2 3
    h.deleteKey(0); // 3
    h.insert(15);  
    h.insert(20);
    h.show();      // 3 15 20
    cout << h.extractMin() << endl; // o/p->3 and arr-> 15 20
    h.show();
    h.decreaseKey(1,1); // 15 1 -> 1 15
    h.show();
    cout << h.extractMin() << endl; // 1
    h.show();
    return 0;
}