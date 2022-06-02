#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *random;
    Node(int x){
        data=x;
        next=random=NULL;
    }
};

void printList(Node* head){
    if(head==NULL) return;
    while(head){
        cout << head->data <<"->" << head->random->data << " "; // in case random is NULL it will give err.
        head=head->next;
    }
    cout << endl;
}

// M-1 using hashmap
Node* clone(Node* head){
    unordered_map<Node*,Node*> ump;
    Node* curr=head;
    while(curr){  // create new nodes for cloned list
        ump[curr] = new Node(curr->data);
        curr=curr->next;
    }
    curr=head;
    while(curr){  // copy pointers from original to cloned list
        ump[curr]->next=ump[curr->next];
        ump[curr]->random=ump[curr->random];
        curr=curr->next;
    }
    return ump[head]; // return head of cloned list
}

// M-2 
Node* clone2(Node* head){
    Node* curr= head,*nex =NULL;
    // step1:  insert new nodes in b/w
    while(curr){
        nex = curr->next;     // store current's next ref. in nex
        curr->next=new Node(curr->data); // insert a new node in b/w
        curr->next->next = nex;
        curr=nex;   // make curr point to nex
    }
    // step2: setting random ptrs for cloned LL
    for(curr=head;curr!=NULL;curr=curr->next->next){
        curr->next->random = (curr->random!=NULL)?curr->random->next:NULL; // to take care of case when rand. of
    }                                                                      // curr. point to NULL
    // step 3: retrieving original and cloned lists
    Node* newhead = new Node(0); // dummy node
    Node* newtail = newhead;
    curr=head;
    while(curr){
        newtail->next = curr->next;
        curr->next = curr->next->next;
        curr = curr->next;
        newtail = newtail->next;
    }
    newtail=newhead;
    newhead=newhead->next;
    delete newtail; // delete dummy node
    return newhead;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(20);
    head->random = head->next->next; // 10->20(1)
    head->next->random = head->random->next; // 5->15
    head->random->random = head;             // 20(1)->10
    head->random->next->random = head->random;// 15->20(1)
    head->next->next->next->next->random = head->next;// 20(2)->5
    printList(head);
    Node* head2 = clone(head);
    printList(head2);
    Node* head3 = clone2(head);
    printList(head3);
    return 0;
}