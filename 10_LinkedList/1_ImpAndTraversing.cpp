#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

// M-1 Iterative method
void printList(Node *head){ // this head ptr is an copy of org. head ptr 
    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

// M-2 Recursive method
void rPrint(Node *head){
    if(head==NULL) return;
    cout << head->data << " ";
    rPrint(head->next);
}

// We could change M-2 to print it in rev. order
void rRevPrint(Node *head){
    if(head==NULL) return;
    rRevPrint(head->next);
    cout << head->data << " ";
}

int main(){
    // M-1 simple way to imp.
    // Node *head = new Node(10);
    // Node *tmp1 = new Node(20);
    // Node *tmp2 = new Node(30);
    // head->next = tmp1;
    // tmp1->next = tmp2;

    // M-2 short imp.
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    // traversing
    printList(head);
    cout << endl;
    printList(head); // to prove that a cpy of head is passed
    cout << endl;
    rPrint(head);
    cout << endl;
    rRevPrint(head);
    return 0; 
}