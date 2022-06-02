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
        arr = new int[c];
    }

    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
    int parent(int i) { return (i-1)/2; }
    // insert
    void insert(int x){
        if(size == capacity) return;
        arr[size]=x;
        for(int i=size;i!=0 && arr[parent(i)]>arr[i];){
            swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }
        size++;
    }
    // heapify
    void minHeapify(int i){
        int lt=left(i),rt=right(i);
        // finding smallest element's index
        int smallest = i;
        if(lt<size && arr[lt]<arr[i]) smallest=lt;
        if(rt<size && arr[rt]<arr[smallest]) smallest=rt;
        // if it is left or right chilt of ith element
        if(smallest!=i){
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
    h.show();
    cout << h.extractMin() << endl;
    h.show();
    return 0;
}