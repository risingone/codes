#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int d){
        data = d;
        prev = NULL;
        next = NULL;
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

int main(){
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    printList(head);
    return 0;
}