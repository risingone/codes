#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* next;
    Node(char x){
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

// M-1 Naive approach
bool isPalindrome(Node* head){
    stack<char> st;
    for(Node* curr=head;curr!=NULL;curr=curr->next){ // traverse the list and put its data in stack
        st.push(curr->data);
    }
    for(Node* curr=head;curr!=NULL;curr=curr->next){
        if(st.top()!=curr->data) return false; // traverse again and match with data at the top of stack
        st.pop();
    }
    return true;
}

Node* reverseList(Node *head){
    if(head==NULL || head->next==NULL) return head;
    Node *curr=head,*prev=NULL,*nex=NULL;
    while(curr){
        nex = curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev; // as prev. become new head;
}

// M-2 efficient approach but it modifies LL
bool isPalindrome2(Node* head){
    if(head==NULL) return true;
    Node *slow = head,*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    // cout << slow->data << endl;
    // reverse the LL after middle node
    Node *rev = reverseList(slow->next);
    // printList(rev);
    Node* curr = head;
    while(rev!=NULL){
        if(rev->data!=curr->data) return false;
        rev = rev->next;
        curr=curr->next;
    }
    return true;
}

int main(){
    Node* head=new Node('R');
    head->next = new Node('A');
    head->next->next = new Node('D');
    head->next->next->next = new Node('A');
    head->next->next->next->next = new Node('R');
    printList(head);
    cout << isPalindrome(head) << endl;
    printList(head);
    cout << isPalindrome2(head) << endl;
    printList(head);
    return 0;
}