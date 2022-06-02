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

// Naive TC: O(n^2)
int height(Node *root){
    if(root==NULL) return 0;
    return 1 +max(height(root->left),height(root->right));
}
bool isBalanced(Node *root){
    if(root==NULL) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh-rh)<=1)&&isBalanced(root->left)&&isBalanced(root->right);
}

// efficient: O(n)
int isBalanced2(Node *root){
    if(root==NULL) return 0;
    // check for left subtree and also gets its height
    int lh=isBalanced2(root->left);
    if(lh==-1) return -1;
    // check for right subtree and also gets its height
    int rh=isBalanced2(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);
}

int main(){
    Node *root = new Node(18);
    root->left = new Node(4);
    root->right = new Node(20);
    root->right->left = new Node(13);
    root->right->right = new Node(10);
    // root->right->right->right = new Node(17);
    cout << isBalanced(root) << endl;
    // return height if balanced, otherwise it return -1
    cout << isBalanced2(root) << endl;
    return 0;
}