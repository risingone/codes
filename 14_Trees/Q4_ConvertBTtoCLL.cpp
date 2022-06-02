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

// print CDLL
void print(Node *root){
    if(!root) return;
    Node *curr=root;
    do{
        cout << curr->key << " ";
        curr=curr->right;
    }while(curr!=root);
}

// to join 2 CLL
Node *concatenate(Node *leftList,Node *rightList){
    if(leftList==NULL) return rightList;
    if(rightList==NULL) return leftList;

    // to get hold of last nodes of both CLL's
    Node *leftLast=leftList->left;
    Node *rightLast=rightList->left;

    // joining 2 CLLs
    leftLast->right=rightList;
    rightList->left=leftLast;
    leftList->left=rightLast;
    rightLast->right=leftList;

    return leftList;
}

Node *bTreeToCList(Node *root){
    if(root==NULL) return NULL;
    // to recursively make CLL of right and left nodes
    Node *left = bTreeToCList(root->left);
    Node *right = bTreeToCList(root->right);

    // to make CLL of root
    root->left=root->right=root;
    // to concatenate first root with left subtree part
    // and then result with right subtree part
    return concatenate(concatenate(left,root),right);
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);
    root=bTreeToCList(root);
    print(root);
    return 0;
}