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

// traversing a circular LL
// M-1
void printList(Node *head){
    if(head==NULL) return;
    cout << (head->data) << " ";
    for(Node* p=head->next;p!=head;p=p->next){
        cout << p->data << " ";
    }
    cout << endl;
}
// M-2
void printList1(Node *head){
    if(head==NULL) return;
    Node *p = head;
    do{
        cout << p->data << " ";
        p = p->next;
    } while(p!=head);
    cout << endl;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;
    printList(head);
    printList1(head);
    return 0;
}