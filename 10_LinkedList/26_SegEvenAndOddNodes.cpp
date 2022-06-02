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
        head = head->next;
    }
    cout << endl;
}

Node* segregate(Node* head){
    Node*eS=NULL,*eE=NULL,*oS=NULL,*oE=NULL; // eS,eE are starting and ending nodes of even ele. LL
    for(Node *curr=head;curr!=NULL;curr=curr->next){ // while oS,oE are for the odd one.
        int x = curr->data;
        if((x%2) == 0){         // if curr->data is odd
            if(eS==NULL){
                eS=curr;
                eE=eS;
            }
            else{
                eE->next = curr;
                eE = eE->next;
            }
        }
        else{                 // else 
            if(oS==NULL){
                oS=curr;
                oE=oS;
            }
            else{
                oE->next = curr;
                oE= oE->next;
            }
        }
    }
    if(oS==NULL||eS==NULL){ // in case LL consists of only even or only odd ele.
        return head;
    }
    eE->next = oS;    // join even and odd ele. LL
    oE->next = NULL;
    return eS;
}

int main(){
    Node* head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(12);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(4); 
    printList(head);  // 17 15 8 12 10 5 4
    head = segregate(head);
    printList(head);  // 8 12 10 4 17 15 5
    return 0;
}