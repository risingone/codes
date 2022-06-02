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

void printKDist(Node *root, int k){
    if(root==NULL) return;
    if(k==0){ cout << root->key << " "; }
    else{
        printKDist(root->left,k-1);
        printKDist(root->right,k-1);
    }
}

int main(){
    int k=2;
    Node *root = new Node(10);         
    root->left = new Node(20);        
    root->right = new Node(30);        
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(70);
    root->right->right->right = new Node(80);
    printKDist(root,k);
    return 0;
}