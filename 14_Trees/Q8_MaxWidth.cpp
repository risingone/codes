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

class Solution {
    int height(Node* root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void preorder(Node *root,int level,int count[]){
        if(!root) return;
        count[level]++;
        preorder(root->left,level+1,count);
        preorder(root->right,level+1,count);
    }
    int getMax(int count[],int h){
        int res=0;
        for(int i=0;i<h;i++){
            res = max(res,count[i]);
        }
        return res;
    }
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        // Your code here
        if(!root) return 0;
        int h=height(root);
        int count[h] = {0};
        int level = 0;
        preorder(root,level,count);
        return getMax(count,h);
    }
};

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    Solution s;
    cout << s.getMaxWidth(root) << endl;
    return 0;
}