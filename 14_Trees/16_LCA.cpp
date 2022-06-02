/*Lowest Common Ancestor
          10
         /  \
        20   30
            /  \
           40   50
    n1=20   n2=50
    path1[] = [10,20]
    path2[] = [10,30,40]
*/
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

// M-1: by finding path
bool findPath(Node *root,vector<Node*> &P,int n){
    if(root==NULL) return false;
    P.push_back(root);
    if(root->key==n) return true;
    if(findPath(root->left,P,n)||findPath(root->right,P,n)){
        return true;
    }
    P.pop_back();
    return false;
}

Node *lca(Node* root,int n1,int n2){
    // to store paths of n1 and n2
    vector<Node*> path1,path2;
    // if one of the n1 or n2 is absent return NULL 
    if(!findPath(root,path1,n1)||!findPath(root,path2,n2)) return NULL;
    // traverse from i=0 till (i+1)th element of path1 & path2 doesn't match
    // then i th element is LCA
    for(int i=0;(i<(path1.size()-1))&&(i<(path2.size()-1));i++){
        if(path1[i+1]!=path2[i+1]) return path1[i];
    }
    return NULL;
}

// M2: Efficient method
Node *lca2(Node *root,int n1,int n2){
    if(root==NULL) return NULL;
    // if n1 or n2 is found
    if(root->key==n1||root->key==n2){
        return root;
    }
    Node *lcaL = lca2(root->left,n1,n2);
    Node *lcaR = lca2(root->right,n1,n2);
    // case1 : when one both nodes are on diff side =) root is LCA
    if(lcaL&&lcaR){
        return root;
    }
    // case2: when both nodes are on same side
    if(lcaL){
        return lcaL;
    }
    else return lcaR;
}

int main(){
    Node *root=new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    Node *res=lca(root,40,50);
    if(res==NULL){
        cout << "LCA is absent" << endl;
    }
    else{
        cout << res->key << endl;
    }
    Node *res2=lca2(root,40,50);
    // before calling it we must be sure LCA exist, otherwise it return node with n1orn2
    cout << res2->key << endl;
    return 0;
}