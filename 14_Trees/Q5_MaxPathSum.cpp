#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){
        data = x;
        left=right=NULL;
    }
};

int findMax(Node *root,int &m){
    if(root==NULL) return 0;
    int lmax = max(0,findMax(root->left,m)); // if max on left or right is < 0
    int rmax = max(0,findMax(root->right,m));// we take 0 to find max sum path
    m=max(m,root->data+lmax+rmax);
    return root->data+max(lmax,rmax);
}

int findMaxSum(Node *root){
    int m=INT_MIN;
    if(!root) return m;
    findMax(root,m);
    return m;
}

int main(){
    Node *root=new Node(10);
    root->left = new Node(2);
    root->right = new Node(5);
    root->right->right = new Node(-2);
    cout << findMaxSum(root) << endl;
    return 0;
}