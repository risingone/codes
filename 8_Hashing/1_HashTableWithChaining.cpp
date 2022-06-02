// Implementation of our own hash table with chaining for collision detection
#include<bits/stdc++.h>
using namespace std;

struct MyHash{
    int BUCKET;
    list<int> *table; //a ptr to doubly LL
    MyHash(int b){
        BUCKET = b;
        table = new list<int>[BUCKET]; // creates a doubly LL array of size BUCKET
    }
    void insert(int k){
        int i = k%BUCKET;
        table[i].push_back(k); // insert at i th location 
    }
    bool search(int k){
        int i = k%BUCKET; // find index of arr
        for(auto x: table[i]){ // traverse the LL to search
            if(x==k) return true;
        }
        return false;
    }
    void remove(int k){
        int i= k%BUCKET;
        table[i].remove(k);
    }
};

int main(){
    MyHash mh(7);
    mh.insert(10);
    mh.insert(20);
    mh.insert(15);
    mh.insert(7);
    cout << mh.search(10) << endl;
    mh.remove(15);
    cout << mh.search(15) << endl;
    return 0;
}