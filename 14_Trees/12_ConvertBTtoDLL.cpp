#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left,*right;
    Node(int x){
        key=x;
        left=right=NULL;
    }
};

void printList(Node *root){
    if(root==NULL) return;
    while(root){
        cout << root->key << " ";
        root = root->right;
    }
    cout << endl;
}

// it will return head of DLL, where right is next and left is previous
Node *BTtoDLL(Node *root){
    if(root==NULL) return root;
    Node *head=BTtoDLL(root->left);
    static Node* prev=NULL;
    if(prev==NULL) head=root;
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    BTtoDLL(root->right);
    return head;
} 

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(35);
    Node *head = BTtoDLL(root);
    printList(head);
    return 0;
}