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

Node* sortList(Node* head){
    if(!head || !(head->next)) return head;
    Node* zeroD = new Node(0);
    Node* oneD = new Node(0);
    Node* twoD = new Node(0);

    Node *zero=zeroD,*one=oneD,*two=twoD;
    Node *curr=head;
    
    while(curr){
        if(curr->data==0){
            zero->next = curr;
            zero=zero->next;
            curr=curr->next;
        } else if(curr->data==1){
            one->next=curr;
            one=one->next;
            curr=curr->next;
        } else{
            two->next=curr;
            two=two->next;
            curr=curr->next;
        }
    }
    zero->next=(oneD->next)?(oneD->next):(twoD->next);
    one->next=twoD->next;
    two->next=NULL;
    head = zeroD->next;

    //Delete dummy nodes
    delete zeroD,oneD,twoD;
    
    return head;
}

int main(){
    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    printList(head); // 2 1 0 1 0
    head = sortList(head);
    printList(head); // 0 0 1 1 2
    return 0;
}