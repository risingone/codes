#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data=x;
        prev=next=NULL;
    }
};

// to check if we can traverse both dir. or not
void printList(Node *head){
    if(head==NULL) return;
    Node* curr=head;
    do{                              // print from head to end node
        cout << curr->data  << " ";
        curr = curr->next;
    }while(curr!=head);
    do{                              // print from end node to head
        curr = curr->prev;
        cout << curr->data << " ";
    }while(curr!=head);
    cout << endl;
}

// Insert at head
Node* insertHead(Node* head, int x){
    Node *temp = new Node(x);
    if(head==NULL){            // to insert 1 node in CDLL
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    temp->prev = head->prev;   // make temp's prev = head's prev
    temp->next = head;         // and next = head
    head->prev->next = temp;   // now insert temp node in b/w
    head->prev = temp;
    return temp;               // return temp as it is new head now
}

int main(){
    Node* head=NULL;
    head = insertHead(head,1);
    head = insertHead(head,11);
    head = insertHead(head,51);
    head = insertHead(head,101); // 101 51 11 1
    printList(head);
    return 0;
}