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

// inorder
void inorder(Node* root){
    if(root==NULL) return;
    Node *curr=root;
    stack<Node *> st;
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

// rec search function
// TC: O(h), Auxilary Space: O(h)
bool search(Node *root,int x){
    if(root==NULL) return false;
    if(root->key==x) return true;
    else if(root->key<x){
        return search(root->right,x);
    } else{
        return search(root->left,x);
    }
}

// iterative search function
// TC: O(h), Auxilary Space: O(1)
bool itsearch(Node *root,int x){
    if(root==NULL) return false;
    while(root){
        if(root->key==x) return true;
        else if(root->key>x){
            root = root->left;
        } else{
            root = root->right;
        }
    }
    return false;
}

int main(){
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(10);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    // we could confirm it is a BST or not by printing
    // inorder traversal, as it always print elements in sorted fashion for BST
    inorder(root);
    cout << endl;
    cout << search(root,60) << endl;
    cout << itsearch(root,80) << endl;
    return 0;
}