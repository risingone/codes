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
// to store time taken to burn
int res=0;
//vit will retrun height and set dist(distance from leaf)
int burnTime(Node *root,int leaf,int &dist){
    if(root==NULL) return 0;
    // set dist to 0 and return height(1)
    if(root->key==leaf){ 
        dist=0; 
        return 1; 
    }
    int ldist=-1,rdist=-1;
    int lh=burnTime(root->left,leaf,ldist);
    int rh=burnTime(root->right,leaf,rdist);
    if(ldist!=-1){
        dist=ldist+1;
        res = max(res,dist+rh);
    }
    else if(rdist!=-1){
        dist=rdist+1;
        res = max(res,dist+lh);
    }
    return max(lh,rh)+1; // returns height
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    root->left->left->left = new Node(40);
    root->left->left->right = new Node(50); 
    int leaf = 50,dist=-1; // to burn it: 3
    // We have to find the farthest Node with given leaf
    cout << burnTime(root,leaf,dist) << endl;
    cout << res << endl;
    return 0;
}