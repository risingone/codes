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

// M-1 : Naive O(n)
int countNode(Node *root){
    if(root==NULL) return 0;
    return 1+countNode(root->left)+countNode(root->right);
}

// M-2 : Efficient O(logn * logn)
int countNode2(Node *root){
    int lh=0,rh=0;
    Node *curr = root;
    // compute height form leftmost node
    while(curr!=NULL){
        lh++;
        curr = curr->left;
    }
    curr=root;
    // compute height from rightmost node
    while(curr!=NULL){
        rh++;
        curr = curr->right;
    }
    // if lh equals rh
    if(lh==rh) return pow(2,lh)-1;
    // else
    else return 1+countNode2(root->left)+countNode2(root->right);
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    cout << countNode(root) << endl;
    cout << countNode2(root) << endl;
    return 0;
}