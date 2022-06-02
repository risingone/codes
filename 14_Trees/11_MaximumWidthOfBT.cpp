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

int maxWidth(Node* root){
    if(root==NULL) return 0;
    queue<Node*> q;
    q.push(root);
    int res=0;
    while(!q.empty()){
        int count=q.size();
        res = max(count,res);
        for(int i=0;i<count;i++){
            Node *curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return res;
}

int main(){
    Node *root = new Node(8);
    root->left = new Node(10);
    root->right = new Node(60);
    root->left->left = new Node(61);
    root->left->right = new Node(77);
    root->right->left = new Node(82);
    // root->right->right = new Node(74);
    cout << maxWidth(root) << endl;
    return 0;
}