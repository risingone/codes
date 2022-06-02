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

int height(Node *root){
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right))+1;
}

int main(){
     /*      10
           /  \
          20   30
         / 
        40  
    */
    Node *root = new Node(10);         
    root->left = new Node(20);        
    root->right = new Node(30);        
    root->left->left = new Node(40);
    cout << height(root) << endl;
    return 0;
}