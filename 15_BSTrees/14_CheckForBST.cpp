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

int maxValue(TreeNode *root){
    if(root==NULL) return INT_MIN;
    int lmax=maxValue(root->left);
    int rmax=maxValue(root->right);
    return max(root->key,max(lmax,rmax));
}

int minValue(TreeNode *root){
    if(root==NULL) return INT_MAX;
    int lmin=minValue(root->left);
    int rmin=minValue(root->right);
    return min(root->key,min(lmin,rmin));
}

// M-1: Naive O(n^2)
bool checkBST(TreeNode *root){
    if(root==NULL) return true;
    // if maxm. value in root->left is > root's value
    if(root->left&&(maxValue(root->left)>root->key)){
        return false;
    }
    // if minm. value in root->right is < root's value
    if(root->right&&(minValue(root->right)<root->key)){
        return false;
    }
    return checkBST(root->left)&&checkBST(root->right);
}

// M-2: Efficient O(n);
bool isBST(TreeNode *root,int min,int max){ // we use range(min,max) in this approach
    if(root==NULL) return true;
    return (root->key>min && root->key<max &&
            isBST(root->left,min,root->key)&& isBST(root->right,root->key,max));
}

// M-3: Efficient O(n) -> in it we use the fact that inorder traversal
// of a BST prints element in sorted fashion
bool isBST2(TreeNode* root,int &prev){
    if(root==NULL) return true;
    if(!isBST2(root->left,prev)) return false;
    if(root->key<=prev) return false;
    prev = root->key;
    return isBST2(root->right,prev);
}

int main(){
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(22); // 18
    root->right->right = new TreeNode(35);
    if(checkBST(root)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
    if(isBST(root,INT_MIN,INT_MAX)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
    int prev=INT_MIN;
    if(isBST2(root,prev)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
    return 0;
}