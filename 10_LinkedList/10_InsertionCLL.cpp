#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next=NULL;
    }
};

// print CLL
void printList(Node *head){
    if(head==NULL) return;
    Node* p=head;
    do{
        cout << p->data << " ";
        p = p->next;
    }while(p!=head);
}

// Insertion at beginning of LL
// Naive Solution
Node* insertBegin(Node *head,int x){
    Node *temp = new Node(x);
    if(head==NULL){           // if head is NULL
        temp->next=temp;      // make temp a CLL on 1 node
    }
    else{
        Node* curr = head;
        while(curr->next != head){ // else traverse to end node
            curr = curr->next;
        }
        curr->next = temp;         // and insert temp
        temp->next = head;
    }
    return temp;              // as temp is new head
}
// efficient Solution
Node* insertBegin1(Node *head,int x){
    Node *temp = new Node(x);
    if(head==NULL){
        temp->next = temp;
        return temp;
    }
    else{
        temp->next = head->next; //add temp node after head in CLL
        head->next = temp;
        int t = head->data;    // swap head and temp's data
        head->data = temp->data;
        temp->data = t;
        return head;
    }
}

// Insertion at the end of CLL
// naive solution
Node *insertEnd(Node *head, int x){
    Node *temp = new Node(x);
    if(head==NULL){           // if head is NULL
        temp->next = temp;    // make temp point to itself
        return temp;          // return temp
    }
    else{
        Node *curr = head;
        while(curr->next != head){ // else traverse to last node
            curr = curr->next;
        }
        curr->next=temp;  //  and add temp in CLL
        temp->next=head;
        return head;      // return head
    }
}
// efficient solution
Node *insertEnd1(Node *head, int x){
    Node *temp = new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next; // insert temp node after head in CLL
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return temp;
    }
}

int main(){
    Node* head = NULL;
    head = insertBegin(head,11);    // 11
    head = insertBegin1(head,21);   // 21 11
    head = insertBegin1(head,51);   // 51 21 11
    head = insertEnd(head,101);     // 51 21 11 101
    head = insertEnd1(head,111);    // 51 21 11 101 111
    printList(head);
    return 0;
}