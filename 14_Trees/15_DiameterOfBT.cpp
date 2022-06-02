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

// Method 1: Naive O(n^2) in case of skew trees
int height(Node *root){
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}

int diameter(Node *root){
    if(root==NULL) return 0;
    int d1 = 1 + height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    return max(d1,max(d2,d3));
}

// Method 2: Better O(n) using unordered map precompute height of every Node
// we use memoization in height function
void height2(Node *root,unordered_map<Node*,int> &ump){
    if(root==NULL) return;
    height2(root->left,ump);
    height2(root->right,ump);
    ump[root]=1+max(ump[root->left],ump[root->right]);
}
int callDiameter(Node* root,unordered_map<Node*,int> &ump){
    if(root==NULL) return 0;
    int d1=1+ ump[root->left] + ump[root->right];
    int d2=callDiameter(root->left,ump);
    int d3=callDiameter(root->right,ump);
    return max(d1,max(d2,d3));
}
int diameter2(Node *root){
    unordered_map<Node*,int> ump;
    ump[NULL]=0;
    // to precompute height of every node
    height2(root,ump);
    // get diameter using ump
    return callDiameter(root,ump);
}

// Method 3: Efficient Solution O(n)
int res=0;
int height3(Node *root){
    if(root==NULL) return 0;
    int lh=height3(root->left);
    int rh=height3(root->right);
    // modified height function
    res = max(res,lh+rh+1);
    return 1 + max(lh,rh);
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(60);
    root->right->left->left = new Node(50);
    root->right->right->right = new Node(70);
    // root->right->left->left->left = new Node(55);
    cout << diameter(root) << endl; // 5
    cout << diameter2(root) << endl;
    // we modify height function to get diameter
    height3(root);
    cout << res << endl;
    return 0;
}