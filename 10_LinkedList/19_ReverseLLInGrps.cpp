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

// recursive Solution
Node* reverseK(Node* head,int k){
    Node* curr=head,*next = NULL,*prev = NULL;
    int count = 0;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL){
        Node* rest_head = reverseK(next,k); // new head for rest of the LL
        head->next = rest_head; // link first k rev. nodes to rem.
    }
    return prev;  // prev is new head
}

// Iterative Solution
Node* reverseK1(Node* head,int k){
    Node* curr = head,*prevFirst = NULL;
    bool isFirstPass = true;
    while(curr!=NULL){
        Node* first= curr,*prev=NULL;
        int count = 0;
        while(curr!=NULL && count<k){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(isFirstPass){  // it will be exec. only once
            head = prev;  // as for firse reversal we have to store head
            isFirstPass = false;
        }
        else{
            prevFirst->next=prev;
        }
        prevFirst = first;        
    }
    return head;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    printList(head);
    // head = reverseK(head,3);
    head = reverseK1(head,3);
    printList(head);
    return 0;
}