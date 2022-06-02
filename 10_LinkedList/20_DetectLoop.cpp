#include<bits/stdc++.h>
using namespace std;

// M-2 O(n) modify Node to add visited of type bool
struct Node{
    int data;
    Node* next;
    bool visited;
    Node(int x){
        data = x;
        next = NULL;
        visited=false;
    }
};

void printList(Node* head){
    if(head==NULL) return;
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

// M-1 absolute naive, for each node traverse all nodes present before it to see
// if next of any of the prev. nodes point to next of curr. node O(n^2)

// M-2
bool detLoop(Node* head){
    while(head!=NULL && head->visited==false){
        head->visited=true;
        head=head->next;
    }
    if(head==NULL) return false;
    return true;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(12);
    head->next->next->next = new Node(20);
    // printList(head);
    head->next->next->next->next = head->next;
    cout << detLoop(head) << endl;
    return 0;
}