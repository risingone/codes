#include<bits/stdc++.h>
using namespace std;

struct MyHash
{
    int *arr;
    int cap,size;
    MyHash(int c){ // create an arr of size c
        cap=c;
        size=0;
        arr = new int[cap];
        for(int i=0;i<cap;i++){ // make all elements -1
            arr[i]=-1;
        }        
    }
    int hash(int key){ // hash function
        return key%cap;
    }
    bool insert(int key){ // insertion function
        if(size==cap) return false; // as array is full
        int i=hash(key);
        // traverse while index is not empty,deleted or = key
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key){
            i=(i+1)%cap; // do circular traversal
        }
        if(arr[i]==key) return false; // as element is already present
        else{
            arr[i]=key;
            size++;
            return true;
        }
    }
    // search function
    bool search(int key){
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1){ // traverse while 1-> don't encounter empty slot
            if(arr[i]==key) return true; // 2-> find key
            i=(i+1)%cap;
            if(i==h) return false; // 3-> come back to starting index
        }
        return false;
    }
    // erase function
    bool erase(int key){
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1){ // 1
            if(arr[i]==key){// 2
                arr[i]=-2;
                return true;
            }
            i=(i+1)%cap;
            if(i==h) return false;// 3 
        }
        return false;
    }
};

int main(){
    MyHash mh(7);
    mh.insert(49);
    mh.insert(56);
    mh.insert(72);
    if(mh.search(56)==true){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    mh.erase(56);
    if(mh.search(56)==true){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}