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

// M-1: Using NULL
void printLevelLine(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        Node *curr=q.front();
        q.pop();
        if(curr==NULL){
            cout << "\n";
            q.push(NULL);
        }
        else{
            cout << curr->key << " ";
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}

// M2: 
void printLevelLine2(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        for(int i=0;i<count;i++){
            Node *curr=q.front();
            q.pop();
            cout << curr->key << " ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        cout << "\n";
    }
}

int main(){
    Node *root = new Node(8);
    root->left = new Node(1);
    root->right = new Node(6);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    root->right->right->left = new Node(3);
    printLevelLine(root);
    cout << endl;
    printLevelLine2(root);
    return 0;
}