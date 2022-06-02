#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next=NULL;
    }
};

int findLen(Node* head){
    int len=0;
    Node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    if(slow!=fast) return -1;
    slow = head;
    while(slow!=fast){  // to find first node of the cycle
        slow=slow->next;
        fast=fast->next;
    }
    cout << slow->data << endl;
    do{                   // to count len. of cycle
        len++;
        fast=fast->next;
    }while(fast!=slow);
    return len;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(12);
    head->next->next->next = new Node(20); // 10 15 12 20
    head->next->next->next->next = head->next; // loop b/w 20 and 15
    cout << findLen(head) << endl;
    return 0;
}