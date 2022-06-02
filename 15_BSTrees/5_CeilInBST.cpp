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

// ceiling Function TC: O(h) Auxilary Space: O(1)
TreeNode *ceil(TreeNode* root,int x){
    TreeNode* res=NULL;
    if(root==NULL) return root;
    while(root){
        if(root->key==x){
            return root;
        } else if(root->key>x){
            res=root;
            root=root->left;
        } else{
            root=root->right;
        }
    }
    return res;
}

// recursive TC:O(n) Auxilary Space: O(h)

int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(30);
    TreeNode *cl=ceil(root,14);
    if(cl){
        cout << cl->key << endl; 
    } else{
        cout << "Ceiling is not present" << endl;
    }
    // TreeNode *cl2=recCeil(root,14);
    // if(cl2){
    //     cout << cl2->key << endl; 
    // } else{
    //     cout << "Ceiling is not present" << endl;
    // }
    return 0;
}