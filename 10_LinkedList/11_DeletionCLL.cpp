#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printList(Node* head){
    if(head==NULL) return;
    Node* curr=head;
    do{
        cout << curr->data << " ";
        curr = curr->next;
    }while(curr!=head);
    cout << endl;
}

// deleting head
// Naive
Node* delHead(Node *head){
    if(head==NULL) return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node* curr=head;
    while(curr->next!=head){ // traverse to the last node
        curr=curr->next;
    }
    curr->next=head->next;
    delete head;
    return curr->next; // as curr->next will be new head
}
// efficient
Node* delHead1(Node *head){
    if(head==NULL) return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    head->data=head->next->data; // copy head->next's data in head
    Node* temp = head->next;     // and delete next node
    head->next = head->next->next;
    delete temp;
    return head;
}

// Delete kth node from a CLL
Node* deleteKth(Node* head,int k){
    if(head==NULL) return head;
    if(k==1) return delHead(head); // to delete head
    Node *curr=head;
    for(int i=0;i<k-2;i++){ // traverse to node present before kth node
        curr = curr->next;
    }
    Node *temp = curr->next;       // take a temp ptr
    curr->next = curr->next->next; // point curr node to kth next node
    delete temp;                   // delete temp
    return head;
}

int main(){
    Node* head= new Node(1);
    head->next=new Node(11);
    head->next->next=new Node(21);
    head->next->next->next=new Node(31);
    head->next->next->next->next=head;
    printList(head);
    // head=delHead(head);
    // head=delHead1(head);
    head = deleteKth(head,3);
    printList(head);
    return 0;
}