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

int getSize(Node* root){
    if(root==NULL) return 0;
    return 1+getSize(root->left)+getSize(root->right);
}
/* We can also do this using Level Order Traversal Function
   by using queue.size() */

int main(){
    Node *root = new Node(8);
    root->left = new Node(1);
    root->right = new Node(6);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    root->right->right->left = new Node(3);
    cout << getSize(root) << endl;
    return 0;
}