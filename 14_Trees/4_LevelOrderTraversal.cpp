#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left,*right;
    Node(int x){
        key = x;
        left = right = NULL;
    }
};

// TC: O(n) Aux. Space: O(n)
void printLevel(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *curr=q.front();
        q.pop();
        cout << curr->key << " ";
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
}

int main(){
    Node *root = new Node(8);
    root->left = new Node(1);
    root->right = new Node(6);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    root->right->right->left = new Node(3);
    printLevel(root);
    return 0;
}