#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left,*right;
    TreeNode(int x){
        data=x;
        left=right=NULL;
    }
};

// Naive O(h+k)
void printKth(TreeNode *root,int &k, int &count){
    if(root){
        printKth(root->left,k,count);
        count++;
        if(count==k){
            cout << root->data << endl;
            return; // without return O(n)
        }
        printKth(root->right,k,count);
    }
}

int main(){
    int k=3,count=0;
    TreeNode *root = new TreeNode(50);
    root->left = new TreeNode(20);
    root->right = new TreeNode(100);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(70);
    root->right->right = new TreeNode(120);
    root->right->left->left = new TreeNode(60);
    root->right->left->right = new TreeNode(80);
    printKth(root,k,count);
    return 0;
}