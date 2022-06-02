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

// inorder traversal
void inorder(TreeNode* root){
    if(root==NULL) return;
    stack<TreeNode*> st;
    TreeNode* curr=root;
    while(curr||!st.empty()){
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }
}

// delete Node
TreeNode *getSuccesor(TreeNode* curr){
    curr=curr->right;
    while(curr!=NULL&&curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
}

TreeNode *delNode(TreeNode *root, int x){
    if(root==NULL) return root;
    if(root->key>x){
        root->left=delNode(root->left,x);
    } else if(root->key<x){
        root->right=delNode(root->right,x);
    } else{
        if(root->left==NULL){
            TreeNode *temp=root->right;
            delete root;
            return temp;
        } else if(root->right==NULL){
            TreeNode *temp=root->left;
            delete root;
            return temp;
        } else{                                      // if there are nodes on both sides we choose just
            TreeNode *succ=getSuccesor(root);       // greater succesor on right side(we can also choos just smaller)
            root->key=succ->key;                     // then make node's(to be deleted) key to succesor's key
            root->right=delNode(root->right,succ->key);// then call delete for right subtree, with x=succ->key
        }
    }
    return root;
}

int main(){
    TreeNode* root=new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);
    inorder(root);
    cout << endl;
    root = delNode(root,80);
    inorder(root);
    cout << endl;
    root = delNode(root,50); // deleting root
    inorder(root);
    cout << endl;
    cout << root->key << endl; // new root
    return 0; 
}