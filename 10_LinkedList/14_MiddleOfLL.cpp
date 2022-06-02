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

// Naive solution
void printMiddle(Node* head){
    if(head==NULL) return;
    int count=0;
    Node* curr;
    for(curr=head;curr!=NULL;curr=curr->next){ // to count no. of nodes in LL
        count++;
    }
    cout << count << endl; // 4
    curr = head;
    for(int i=0;i<(count/2);i++){   // move curr to (count/2)th node
        curr = curr->next;
    }
    cout << curr->data << endl;     // print it's data
}

// efficient solution
void printMiddle1(Node* head){
    if(head==NULL) return;
    Node *slow=head,*fast=head;    // take 2 ptr's initialize both to head
    while(fast!=NULL && fast->next!=NULL){ // move one by 1 step
        slow = slow->next;                 // and other by 2 steps
        fast = fast->next->next;           // till fast(even ele.) or fast's next(odd ele.) become NULL
    }
    cout << slow->data << endl;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(11);
    head->next->next->next = new Node(21);
    // in case of even ele. it print 2's data
    printMiddle(head); // 11
    printMiddle1(head);
    return 0;
}