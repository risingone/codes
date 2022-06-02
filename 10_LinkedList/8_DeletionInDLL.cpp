#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data = x;
        next=prev=NULL;
    }
};

// check
void printList(Node* head){
    if(head==NULL) return;
    while(head->next){
        cout << head->data << " ";
        head = head->next;
    }
    while(head){
        cout << head->data << " ";
        head = head->prev;
    }
    cout << endl;
}

// Delete head
Node *delHead(Node *head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    else{
        Node *temp = head; // take a temp ptr to head
        head=head->next;   // make head=head->next
        head->prev=NULL;   // modify head's prev
        delete temp;       // delete temp
        return head;
    }
}

// Delete Last Node
Node *delLast(Node *head){
    if(head==NULL) return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next != NULL){ // traverse to last node
        curr = curr->next;
    }
    curr->prev->next=NULL;  // make curr. prev ele. next ptr point to NULL
    delete curr;
    return head;
}

int main(){
    Node *head = new Node(11);
    Node *temp1 = new Node(21);
    Node *temp2 = new Node(51);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    head = delHead(head);
    head = delLast(head);
    printList(head);
    return 0;
}