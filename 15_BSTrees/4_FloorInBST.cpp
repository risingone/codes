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

// floor of x
TreeNode *floor(TreeNode *root,int x){
    TreeNode *res=NULL;
    while(root!=NULL){
        if(root->key==x) return root;
        else if(root->key>x){
            root=root->left;
        } else{
            res=root;
            root=root->right;
        }
    }
    return res;
}

int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(30);
    TreeNode *fl=floor(root,14);
    cout << fl->key << endl;
    return 0;
}