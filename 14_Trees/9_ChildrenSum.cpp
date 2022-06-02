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

bool isCSum(Node *root){
    if(root==NULL) return true;
    // if a Node doesn't have left and right Node's we return true
    if(root->left==NULL && root->right==NULL) return true;
    int sum=0;
    if(root->left){
        sum += root->left->key;
    }
    if(root->right){
        sum += root->right->key;
    }
    return (sum==root->key && isCSum(root->left) && isCSum(root->right));
}

int main(){
    /*        20
             /  \
            8    12
           / \ 
          3   5
    */
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    cout << isCSum(root) << endl;
}