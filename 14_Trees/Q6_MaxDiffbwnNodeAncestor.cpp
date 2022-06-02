#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};

int maxd(Node *root,int &m){
    if(root==NULL) return INT_MAX;
    int lmn = maxd(root->left,m);
    int rmn = maxd(root->right,m);
    if(root->left||root->right){
        m = max(m,root->data-min(lmn,rmn));
    }
    return min(root->data,min(lmn,rmn));
}

int maxDiff(Node *root){
    int m=INT_MIN;
    if(root==NULL) return m;
    maxd(root,m);
    return m; 
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(7);
    cout << maxDiff(root) << endl; 
    return 0;
}