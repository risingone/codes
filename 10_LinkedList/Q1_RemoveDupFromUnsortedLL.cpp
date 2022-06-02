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
        head = head->next;
    }
    cout << endl;
}

Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_set<int> ust;  // to check if ele. occ. previously
     Node* curr=head;
     Node* prev=NULL;
     while(curr){
         if(ust.find(curr->data)!=ust.end()){ // if it occured previously
             prev->next=curr->next;           // make it's prev. point to its next
             delete curr;                     // and delete this node
             curr = prev->next;
         }else{
             ust.insert(curr->data);          // else insert curr. node's data into map
             prev=curr;                       // and traverse forward
             curr=curr->next;
         }
     }
     return head;
    }

int main(){
    Node* head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(7);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(2);
    printList(head);              // 5 2 7 5 2
    head = removeDuplicates(head);
    printList(head);              // 5 2 7
    return 0;
}