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

void vSumR(Node *root,int hd,map<int,int>& mp){
    if(root==NULL) return;
    vSumR(root->left,hd-1,mp);
    mp[hd] += root->key;
    vSumR(root->right,hd+1,mp);
}

// O(n log(hd) + hd) hd-> total no. of possible horizontal distances
void vSum(Node *root){
    if(root==NULL) return;
    map<int,int> mp;
    vSumR(root,0,mp);
    for(auto &it: mp){
        cout << it.second << " ";
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    vSum(root);
    return 0;
}