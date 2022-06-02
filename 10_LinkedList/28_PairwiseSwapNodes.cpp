#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* head){
    if(head==NULL) return;
    while(head){
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

// M-1: changing data
void pairwiseSwap(Node* head){
    Node* curr = head;
    while(curr!=NULL && curr->next!=NULL){
        swap(curr->data, curr->next->data);  // swap curr. and its next's data
        curr=curr->next->next;               // move curr. by 2 steps
    }
}

// M-2: changing pointers/references
Node *pairwiseSwap2(Node* head){
    if(head==NULL||head->next==NULL) return head;
    // we do 1 reversal separately as head will be changed
    Node *curr=head->next->next; // store ref. to 3 node
    Node *prev=head; // prev. node for link reversal
    head=head->next; // make head point to 2 node as it will be new head
    head->next = prev; // reverse links
    while(curr!=NULL&&curr->next!=NULL){
        prev->next=curr->next; // link prev. reversed pair to curr. reversing pair
        prev = curr;
        Node *next = curr->next->next; // to update curr. after link reversal
        curr->next->next = curr; // link reversal
        curr = next;
    }
    prev->next=curr; // to complete list
    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    printList(head); // 1 2 3 4 5 6
    pairwiseSwap(head);
    printList(head); // 2 1 4 3 6 5
    head = pairwiseSwap2(head);
    printList(head);
    return 0;
}