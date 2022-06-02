#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left,*right;
    Node(int x){
        key = x;
        left=right=NULL;
    }
};

void Tview(Node *root){
    if(root==NULL) return;
    map<int,int> mp;
    queue<pair<int,Node *>> q;
    q.push({0,root});
    while(!q.empty()){
        pair<int,Node *> p=q.front();
        q.pop();
        int hd = p.first;
        Node *curr=p.second;
        if(mp.find(hd)==mp.end()){
            mp[hd]=curr->key;
        }
        if(curr->left) q.push({hd-1,curr->left});
        if(curr->right) q.push({hd+1,curr->right});
    }
    for(auto &it: mp){
        cout << it.second << " ";
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(50);
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    Tview(root);
    return 0;
}