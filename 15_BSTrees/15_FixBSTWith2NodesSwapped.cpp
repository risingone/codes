#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left,*right;
    Node(int x){
        key=x;
        left = right = NULL;
    }
};
// inorder traversal
void inorder(Node *root){
    if(root==NULL) return;
    stack<Node *> s;
    Node *curr=root;
    while(curr!=NULL||!s.empty()){
        while(curr){
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout << curr->key << " ";
        curr=curr->right;
    }
}

Node *pre=NULL,*first=NULL,*second=NULL;
void fixBST(Node *root){
    if(root==NULL) return;
    fixBST(root->left);
    if(pre!=NULL && root->key < pre->key){
        if(first==NULL) first=pre;
        second=root;
    }
    pre=root;
    fixBST(root->right);
}

int main(){
    Node *root=new Node(20);
    root->left = new Node(60);
    root->right = new Node(80); //1
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->right->left = new Node(8); //2
    root->right->right = new Node(100);
    inorder(root);
    cout << endl;
    // get fold of nodes to be swapped
    fixBST(root);
    //swapping nodes to fix BT
    int temp = first->key;
    first->key=second->key;
    second->key=temp;
    inorder(root);
    return 0;
}