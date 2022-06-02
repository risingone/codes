#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left,*right;
    int lcount; // we also store lcount for each element
    Node(int x){
        key=x;
        left=NULL;
        right=NULL;
        lcount=0;
    }
};

Node* insert(Node *root,int x){
    if(root==NULL) return new Node(x);
    if(x<root->key){
        // while inserting on left increment lcount for each node by 1
        root->left = insert(root->left,x);
        root->lcount++;
    } else if(x>root->key){
        root->right = insert(root->right,x);
    }
    return root;
}

Node* kthSmallest(Node* root, int k){
    if(root==NULL) return NULL;
    int count = root->lcount + 1;
    if(count == k)
        return root;
    if(count>k)
        return kthSmallest(root->left,k);
    return kthSmallest(root->right,k-count);
}

int main(){
    Node *root=NULL;
    int keys[] = {20,8,22,4,12,10,14};
    for(int x:keys){
        root = insert(root,x);
    }
    int k=4;
    Node *res = kthSmallest(root, k);
    if(res == NULL){
        cout << "There are less than k nodes in the BST";
    } else{
        cout << "K-th Smallest Element is " << res->key;
    }
    return 0;
}