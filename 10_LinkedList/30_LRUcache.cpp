#include<bits/stdc++.h>
using namespace std;

// node of doubly LL
class Node{
    public:
    int key;
    int value;
    Node *pre;
    Node *next;
    Node(int k,int v){
        key = k;
        value = v;
        pre=NULL;
        next=NULL;
    }
};

class LRUCache {
    public:
    unordered_map<int,Node*> map;
    int capacity,count;
    Node *head, *tail;
    // to make doubly LL cache
    LRUCache(int c){
        capacity = c;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->pre = head;
        head->pre = NULL;
        tail->next = NULL;
        count = 0;
    }

    void deleteNode(Node *node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void addToHead(Node *node){
        node->next = head->next;
        node->next->pre = node;
        node->pre = head;
        head->next = node;
    }
    // to search a prticular key in the DLL cache
    int get(int key){
        if(map[key]!=NULL){ // if key is found
            Node *node = map[key]; // get ref. to the node
            int result = node->value;
            deleteNode(node); // remove node from DLL
            addToHead(node);  // and add it in front
            cout << "Got the value: " << result << " for the key: " << key << endl;
            return result;
        }
        cout << "Did not get any value" << " for the key: " << key << endl;
        return -1;
    }
    void set(int key, int value){
        cout << "Going to set the (key, value) : (" << key << ", " << value <<")" << endl;
        if(map[key] != NULL){
            Node *node = map[key];
            node->value = value;
            deleteNode(node);
            addToHead(node);
        } 
        else{
            Node *node = new Node(key,value);
            map[key] = node;
            if(count<capacity){ // check for capacity
                count++;        // if not full add at starting
                addToHead(node);
            }
            else{               // else remove node before tail
                map.erase(tail->pre->key); // also erase it from map
                deleteNode(tail->pre);    // and add node at begining
                addToHead(node);
            }
        }
    }
};

int main(){
    // create cache of capacity 2
    LRUCache cache(2); 
    // store a key(1) with value 10 in cache
    cache.set(1, 10);
    // store another key(2) with value 20 in cache
    cache.set(2, 20);
    cout << "Value for the key: 1 is " << cache.get(1) << endl; // returns 10

    // removing key 2 and store a key(2) with value 30 in cache
    cache.set(3, 30);
    cout << "Value for the key: 2 is " << cache.get(2) << endl; // return -1(not found)

    // removing key 1 and store a key 4) with value 40 in the cache.
    cache.set(4, 40);
    
    cout << "Value for the key: 1 is " << cache.get(1) << endl; // return -1(not found)
    cout << "Value for the key: 3 is " << cache.get(3) << endl; // return 30
    cout << "Value for the key: 4 is " << cache.get(4) << endl; // return 40
    return 0;
}