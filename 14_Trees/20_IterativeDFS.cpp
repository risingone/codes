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
void IterativeInorder(Node *root){
    stack<Node *>st;
    Node *curr = root;
    while(curr!=NULL||!st.empty()){
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout << curr->key << " ";
        curr=curr->right;
    }
}

// preorder
void IterativePreorder(Node *root){
    if(root==NULL) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* curr=st.top();
        st.pop();
        cout << curr->key << " ";
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left); 
    }
}

// space optimized preorder
void IterativePreorder2(Node *root){
    stack<Node*> st;
    Node *curr = root;
    while(curr||!st.empty()){
        while(curr){
            cout << curr->key << " ";
            if(curr->right) st.push(curr->right);
            curr=curr->left;
        }
        if(!st.empty()){
            curr=st.top();
            st.pop();
        }
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    IterativeInorder(root);
    cout << endl;
    IterativePreorder(root);
    cout << endl;
    IterativePreorder2(root);
    return 0;
}