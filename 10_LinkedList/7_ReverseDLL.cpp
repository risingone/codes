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

// reverse a DLL
Node *reverseDLL(Node *head){
    if(head==NULL||head->next==NULL) return head;
    Node *temp=NULL,*curr=head;
    while(curr!=NULL){
        temp = curr->prev;         // we swap next and prev ptr
        curr->prev = curr->next;   // using a temp ptr
        curr->next = temp;
        curr = curr->prev;         // move to next using prev as linked are reversed
    }
    return temp->prev;
}

int main(){
    Node* head = new Node(1);
    Node* temp1 = new Node(11);
    Node* temp2 = new Node(21);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    printList(head);
    head = reverseDLL(head);
    printList(head);
    return 0;
}