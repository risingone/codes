#include<bits/stdc++.h>
using namespace std;
// LC 148 for better understanding
struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* head){
    if(head==NULL) return;
    while(head){
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

void FindMiddle(Node* cur,Node** first,Node** second){
    Node* fast;
    Node* slow;
    slow = cur;
    fast = cur;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    *first = cur;
    *second=slow->next;
    slow->next=NULL;
}

Node* MergeBoth(Node* a, Node* b){
    if(a==NULL) return b;    // if one of the LL
    if(b==NULL) return a;    // is NULL return other
    Node *head = NULL,*tail=NULL;
    if(a->data<b->data){    // initialize head and tail
        head=tail=a;
        a=a->next;
    }
    else{
        head=tail=b;
        b=b->next;
    }
    while(a!=NULL && b!=NULL){
        if(a->data<=b->data){
            tail->next=a;
            tail=a;
            a=a->next;
        }
        else{
            tail->next = b;
            tail = b;
            b = b->next;
        }
    } // if one of the LL exhausts link rest of the other LL
    if(a==NULL) tail->next = b;
    else tail->next = a;
    return head; // return head of the new LL
}

void MergeSorting(Node** head){ // ptr to head ptr
    Node* cur = *head; // as head is ptr to head ptr
    Node* first;
    Node* second;
    if(!cur || !cur->next) return; // if curr. node is NULL or its next is NULL
    FindMiddle(cur,&first,&second); // to divide LL into 2 = parts
    MergeSorting(&first);
    MergeSorting(&second);
    *head = MergeBoth(first,second); // merge 2 sorted LL
}

Node* mergeSort(Node* head){
    MergeSorting(&head);
    return head;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(9);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(51);
    printList(head);
    head = mergeSort(head);
    printList(head);
    return 0;
}