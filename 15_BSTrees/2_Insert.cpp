#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int key;
    TreeNode *left,*right;
    TreeNode(int x){
        key=x;
        left=right=NULL;
    }
};

// inorder
void inorder(TreeNode* root){
    if(root==NULL) return;
    stack<TreeNode*> s;
    TreeNode* curr=root;
    while(curr||!s.empty()){
        while(curr){
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        cout << curr->key << " ";
        s.pop();
        curr=curr->right;
    }
}

// recursive insert
TreeNode *insert(TreeNode *root,int x){
    if(root==NULL) return new TreeNode(x);
    else if(root->key<x){
        root->right=insert(root->right,x);
    } else{
        root->left=insert(root->left,x);
    }
    return root;
}

// iterative insert
TreeNode *itinsert(TreeNode *root,int x){
    TreeNode *temp = new TreeNode(x);
    TreeNode *parent=NULL,*curr=root;
    while(curr){
        parent=curr; // it will act as follower
        if(curr->key>x){
            curr=curr->left;
        } else if(curr->key<x){
            curr=curr->right;
        } else{ // when node is already present
            return root;
        }
    }
    if(parent==NULL) return temp; // if no node is present in tree
    if(parent->key>x){
        parent->left = temp;
    }
    else{
        parent->right = temp;
    }
    return root;
}

int main(){
    TreeNode *root=new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);
    inorder(root);
    cout << endl;
    insert(root,20);
    inorder(root);
    cout << endl;
    // Make tree similar to above one using insert;
    TreeNode* root2=NULL;
    // root2 = insert(root2,10);
    // insert(root2,5);
    // insert(root2,15);
    // insert(root2,12);
    // insert(root2,18);
    root2 = itinsert(root2,10);
    itinsert(root2,5);
    itinsert(root2,15);
    itinsert(root2,12);
    itinsert(root2,18);
    inorder(root2);
    return 0;
}