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

int getMax(Node* root){
    if(root==NULL) return INT_MIN;
    return max(root->key,max(getMax(root->left),getMax(root->right)));
}
/* We can also do this using Level Order Traversal Function*/

int main(){
    Node *root = new Node(8);
    root->left = new Node(10);
    root->right = new Node(60);
    root->left->left = new Node(61);
    root->left->right = new Node(77);
    root->right->left = new Node(82);
    root->right->right = new Node(74);
    cout << getMax(root) << endl;
    return 0;
}