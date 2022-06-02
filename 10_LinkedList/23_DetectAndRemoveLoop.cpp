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
        head = head->next;
    }
    cout << endl;
}

void detectRemoveLoop(Node* head){
    Node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    if(slow!=fast) return; // as there is no loop
    slow=head;
    while(slow->next!=fast->next){  // when we make slow!= fast, we get node from where loop begin
        slow=slow->next;            // in this case fast will be at last node
        fast=fast->next;
    }
    fast->next=NULL; // so we make its next NULL, hence loop is gone
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(12);
    head->next->next->next = new Node(20); // 10 15 12 20
    head->next->next->next->next = head->next; // loop b/w 20 and 15
    detectRemoveLoop(head);
    printList(head);
    return 0;
}