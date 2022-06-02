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

void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
    return;
}

// constructing BT O(n^2)
int preIndex=0;
Node *cTree(int in[],int pre[],int is,int ie){
    if(is>ie) return NULL;
    Node* root=new Node(pre[preIndex++]);
    int inIndex;
    for(int i=is;i<=ie;i++){
        if(in[i]==root->key){
            inIndex = i;
            break;
        }
    }
    root->left=cTree(in,pre,is,inIndex-1);
    root->right=cTree(in,pre,inIndex+1,ie);
    return root;
}

// with hashing O(n)
int pInd=0;
Node* cTree2(unordered_map<int,int>& ump,int pre[],int si,int ei){
    if(si>ei) return NULL;
    Node *root=new Node(pre[pInd++]);
    // now use ump to call recursively for left and right subtree
    root->left=cTree2(ump,pre,si,ump[root->key]-1);
    root->right=cTree2(ump,pre,ump[root->key]+1,ei);
    return root;
}

int main(){
    int in[]={20,10,40,30,50};
    int pre[]={10,20,30,40,50};
    int n=sizeof(pre)/sizeof(pre[0]);
    Node *root=cTree(in,pre,0,n-1);
    // inorder traversal to check
    inorder(root);
    cout << endl;
    // M-2
    unordered_map<int,int> ump;
    for(int i=0;i<5;i++){
        ump[in[i]]=i;
    }
    Node *root2=cTree2(ump,pre,0,n-1);
    inorder(root2);
    return 0;
}