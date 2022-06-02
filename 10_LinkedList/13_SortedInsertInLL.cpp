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

void printList(Node *head){
    if(head==NULL) return;
    while(head!=NULL){
        cout << head->data <<  " ";
        head = head->next;
    }
}

Node *sortInsert(Node *head,int x){
    Node *temp = new Node(x);
    if(head==NULL) return temp;
    if(x<head->data){
        temp->next = head;
        return temp;
    }
    Node* curr = head;
    while(curr->next!=NULL && curr->next->data<x){ // traverse while next node's data < x 
         curr = curr->next;                        // or last node if all nodes are < x
    }
    temp->next = curr->next;  // then add temp node
    curr->next = temp;
    return head;
}

int main(){
    Node* head = new Node(11);
    head->next = new Node(21);
    head->next->next = new Node(31); // 11 21 31 made a sorted LL
    head = sortInsert(head,25);
    head = sortInsert(head,51);
    printList(head);
    return 0;
}