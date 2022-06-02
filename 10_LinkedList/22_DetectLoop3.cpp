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

// M-4 in it we use hashing O(n)
bool isLoop(Node* head){
    unordered_set<Node *> s;
    for(Node* curr=head; curr!=NULL; curr=curr->next){
        if(s.find(curr)!=s.end()){   // if node is already present
            return true;
        }
        s.insert(curr);             // else insert node
    }
    return false;
}

// M-5 Floyd's cycle detection
bool isLoop1(Node* head){
    Node *fast=head,*slow=head;
    while(fast!=NULL && fast->next!=NULL){ // if there is no loop and fast bec. NULL
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){   // in case of loop slow ==fast
            return true;
        }
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
    cout << isLoop1(head) << endl;
    return 0;
}