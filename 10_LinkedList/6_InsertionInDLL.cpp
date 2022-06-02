#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node *prev;
    Node(int d){
        data = d;
        next = prev = NULL;
    }
};

// to check if we can traverse both dir. or not
void printList(Node *head){
    if(head==NULL) return;
    while(head->next){
        cout << head->data  << " ";
        head = head->next;
    }
    while(head){
        cout << head->data << " ";
        head = head->prev;
    }
    cout << endl;
}

// to insert in the begining of DLL
Node *insertBegin(Node *head, int data){
    Node *temp = new Node(data);
    temp->next = head;
    if(head != NULL) head->prev = temp; // as NULL->prev is undefined
    return temp;
}

// to insert at the end of DLL
Node *insertEnd(Node *head, int data){
    Node *temp = new Node(data);
    if(head==NULL) return temp;   // if head is NULL, new created node is new head
    Node *curr = head;
    while(curr->next != NULL){ // else traverse to last node
        curr = curr->next;
    }
    curr->next = temp;  // and link it
    temp->prev = curr;
    return head;
}

int main(){
    Node *head = NULL;
    head = insertEnd(head,51);
    head = insertBegin(head,1);
    head = insertEnd(head,81);
    head = insertBegin(head,0);
    printList(head);
    return 0;
}