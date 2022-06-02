#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printList(Node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

// M-1 Insertion at Begining
Node *insertBegin(Node *head,int x){
    Node *temp = new Node(x); // create new Node
    temp->next = head;        // insert it at begin
    return temp;              // return it to modify head
}

// M-2 Insertion at End
Node* insertEnd(Node *head,int x){
    Node *temp = new Node(x);
    if(head==NULL) return temp;
    Node* curr=head;
    while(curr->next){          // traverse to the last node
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

// M-3 Insertion at given position
Node* insertPos(Node *head,int pos,int data){
    Node* temp = new Node(data);
    if(pos==1){                     // to insert at 1 pos.
        temp->next=head;
        return temp;
    }
    Node* curr = head;
    for(int i=1;i<=pos-2 && curr!=NULL;i++){
        curr = curr->next;
    }
    if(curr==NULL) return head;    // if pos. is beyond LL length
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

int main(){
    Node *head = NULL;
    head = insertEnd(head,1);    // 1
    head = insertBegin(head,10); // 10 1
    head = insertBegin(head,20); // 20 10 1
    head = insertBegin(head,30); // 30 20 10 1
    head = insertEnd(head,50);          // 30 20 10 1 50
    head = insertEnd(head,15);          // 30 20 10 1 50 15
    head = insertPos(head,3,22);        // 30 20 22 10 1 50 15
    printList(head);
    return 0;
}