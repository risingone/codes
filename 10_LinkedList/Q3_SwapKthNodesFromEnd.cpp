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
        head=head->next;
    }
    cout << endl;
}

Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
    if(K>num) return head;
    Node *curr = head;
    if(K==1||K==num){ // in this case first and last node changes
        Node *foll;
        curr=head;
        while(curr->next){
            foll=curr;
            curr=curr->next;
        }
        curr->next=head->next;
        head->next=NULL;
        foll->next=head;
        return curr;
    }
    else{
        Node *first=head,*second=head; // to point to Kth node from starting and end
        Node *fprev=NULL,*sprev=NULL;  // follower ptr's for both
        for(int i=0;i<K-1;i++){
            fprev=first;
            first=first->next;
        }
        for(int i=0;i<(num-K);i++){
            sprev=second;
            second=second->next;
        }
        if(first==second){ // if both point to same node
            return head;
        }
        else if(sprev==first){ // if both are consq. and first is before sec.
            fprev->next=second;
            first->next=second->next;
            second->next=first;
        }
        else if(second==fprev){ // if both are consq. and second is before first
            sprev->next=first;
            second->next=first->next;
            first->next=second;
        }
        else{                 // in all other cases simply swap both the nodes
            Node* fnext=first->next;
            first->next=second->next;
            second->next=fnext;
            sprev->next=first;
            fprev->next=second;
        }
    }
    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    printList(head);
    head = swapkthnode(head,4,1);
    printList(head);
    return 0;
}