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
    while(head){
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

Node* sortedMerge(Node* a, Node* b){
    if(a==NULL) return b;    // if one of the LL
    if(b==NULL) return a;    // is NULL return other
    Node *head = NULL,*tail=NULL;
    if(a->data<b->data){    // initialize head and tail
        head=tail=a;
        a=a->next;
    }
    else{
        head=tail=b;
        b=b->next;
    }
    while(a!=NULL && b!=NULL){
        if(a->data<=b->data){
            tail->next=a;
            tail=a;
            a=a->next;
        }
        else{
            tail->next = b;
            tail = b;
            b = b->next;
        }
    } // if one of the LL exhausts link rest of the other LL
    if(a==NULL) tail->next = b;
    else tail->next = a;
    return head; // return head of the new LL
}

int main(){
    Node *head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30); // 10 20 30
    Node *head2 = new Node(15);
    head2->next = new Node(35); // 5 35
    printList(head1);
    printList(head2);
    Node *head = sortedMerge(head1,head2);
    printList(head);
    return 0;
}