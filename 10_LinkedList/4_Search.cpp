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

// M-1 Iterative search
int search(Node *head, int x){
    int pos=1;
    Node* curr = head;
    while(curr != NULL){
        if(curr->data==x) return pos;
        else{
            pos++;
            curr = curr->next;
        }
    }
    return -1;
}

// M-2 Recursive search
int rSearch(Node *head,int x){
    if(head==NULL) return -1;            // when head become NULL
    if(head->data==x){                   // when we get data
        return 1;
    }
    else{
        int res = rSearch(head->next,x);  // otherwise keep on traversing
        if(res==-1) return -1;            // return res. acc. to rec. calls
        else return (res+1);
    }
}

int main(){
    Node* head = new Node(11);
    head->next = new Node(22);
    head->next->next = new Node(33);
    cout << search(head, 22) << endl;
    cout << rSearch(head, 33) << endl;
    return 0;
}