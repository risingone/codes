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

// M1: Recursive
void printLeft(Node* root,int level,int &max){
    if(root==NULL) return;
    if(max<level){
        cout << root->key << " ";
        max++;
    }
    if(root->left) printLeft(root->left,level+1,max);
    if(root->right) printLeft(root->right,level+1,max);
    return;
}

void printLeftView(Node *root){
    int max=0;
    printLeft(root,1,max);
}

// M2: Iterative
void printLeft2(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        for(int i=0;i<count;i++){
            Node *curr=q.front();
            q.pop();
            if(i==0){
                cout << curr->key << " ";
            }
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
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
    printLeftView(root);
    cout << endl;
    printLeft2(root);
    return 0;
}