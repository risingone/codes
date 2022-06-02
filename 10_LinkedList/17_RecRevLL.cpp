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

// print LL
void printList(Node* head){
    if(head==NULL) return;
    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// M-1
Node* recRev(Node* head){
    if(head==NULL||head->next==NULL){  // base case
        return head;
    }
    // we first go till base case to find new head(rest_head)
    Node* rest_head = recRev(head->next);
    // rest_tail point to leftmost node of rev. list
    Node* rest_tail = head->next; // as head is passed in rec. call
    rest_tail->next = head; // reverse the link
    head->next = NULL; // make head->next NULL as it still points to rest_tail
    return rest_head;
}

// M-2
Node* recRev1(Node* curr, Node* prev){
    if(curr==NULL){  // base condition
        return prev; // as prev is new head
    }
    Node* next = curr->next;
    curr->next = prev;
    return recRev1(next, curr);
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);
    printList(head);
    head = recRev(head);
    printList(head);
    head = recRev1(head,NULL);
    printList(head);
    return 0;
}