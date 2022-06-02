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

// Naive
void printNthFromEnd(Node *head,int n){
    int len=0;
    for(Node* curr=head;curr!=NULL;curr=curr->next){ // cal. len. of LL
        len++;
    }
    if(len<n){ // if len<n return
        return;
    }
    Node* curr=head;
    for(int i=0;i<(len-n);i++){  // move curr (len-n) steps
        curr = curr->next;
    }
    cout << curr->data << endl;
}
// efficient
void printNthEnd(Node* head,int n){
    if(head==NULL) return;
    Node* first = head;
    for(int i=0;i<n;i++){                  // move first ptr n steps
        if(first==NULL) return;           // if len. is < n return
        first = first->next;
    }
    Node* second = head;
    while(first!=NULL){                   // then move both first and second by 1 step
        second=second->next;              // as fast is n steps ahead, when first point to NULL
        first=first->next;                // slow will be pointing to nth Node from end
    }
    cout << second->data << endl;
}


int main(){
    Node* head = new Node(1);
    head->next = new Node(7);
    head->next->next = new Node(11);
    head->next->next->next = new Node(21);
    printNthFromEnd(head,3);
    printNthEnd(head,2);
    return 0; 
}