#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(){}; // default constructor
    Node(int x){
        data = x;
        next = NULL;  
    }
};
// M-3 in it we modify ptrs/refrences to LL
bool isLoop(Node *head){
    Node *temp = new Node;
    Node* curr = head;
    while(curr!=NULL){
        if(curr->next == NULL) return false; // in case of no loop
        if(curr->next == temp) return true; // in case of loop curr->next will be already modified to point to temp
        Node* curr_next = curr->next;   // we store curr->next node
        curr->next = temp;              // then make curr point to temp
        curr = curr_next;               // and make curr = stored curr->next
    }
    return false;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(12);
    head->next->next->next = new Node(20); // 10 15 12 20
    head->next->next->next->next = head->next; // loop b/w 20 and 15
    cout << isLoop(head) << endl;
    return 0;
}