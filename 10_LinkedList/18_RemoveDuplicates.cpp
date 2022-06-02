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

// Function to remove duplicate elements
void RemoveDups(Node* head){
    Node* curr = head;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->data==curr->next->data){ // if next nodes data is same as current node's data
            Node* temp = curr->next;      // delete next node
            curr->next = curr->next->next;
            delete(temp);                  // we don't move curr here as next node's data might be = 
        }
        else{
            curr=curr->next;
        }
    }
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = new Node(30); // 10 20 20 30 30 30
    printList(head);
    RemoveDups(head);
    printList(head);
    return 0;
}