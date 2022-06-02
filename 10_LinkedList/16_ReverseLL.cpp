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

// Naive Solution
Node* revList(Node *head){
    vector<int> vec;
    for(Node* curr=head;curr!=NULL;curr=curr->next){ // copy list's data to a vector
        vec.push_back(curr->data);
    }
    for(Node* curr=head;curr!=NULL;curr=curr->next){ // copy data back to list in rev. order
        curr->data = vec.back();
        vec.pop_back();
    }
    return head;
}

// efficient Solution
Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL){  // keep on reversing LL till curr become NULL
        Node *nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev; // as prev is new head
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);
    printList(head);
    head = revList(head);
    printList(head);
    head = reverse(head);
    printList(head);
    return 0;
}