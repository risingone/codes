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
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteNode(Node* ptr){
    Node *temp = ptr->next; //copy next node's data in it
    ptr->data = temp->data; // then delete next node
    ptr->next = temp->next;
    delete temp;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(21);
    head->next->next = new Node(51);
    head->next->next->next = new Node(111);
    printList(head);
    deleteNode(head->next);
    printList(head);
    return 0;
}
