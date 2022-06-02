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
// printing
void printList(Node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Deleting First Node
Node* delHead(Node* head){
    if(!head) return NULL;
    Node* temp = head->next;
    delete head;
    return temp;
}

// Deleting Last Node
Node* delLast(Node* head){
    if(head==NULL) return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next){ // traverse to 2 last node
        curr=curr->next;
    }
    delete curr->next;
    curr->next=NULL;
    return head;
}

int main(){
    Node* head = new Node(11);
    head->next = new Node(21);
    head->next->next = new Node(51);
    head->next->next->next = new Node(101);
    printList(head);  // 11 21 51 101
    head = delHead(head);
    printList(head);  // 21 51 101
    head = delLast(head);
    printList(head);  // 21 51
    return 0;
}