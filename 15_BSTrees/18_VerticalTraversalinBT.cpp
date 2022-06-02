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

void vTraversal(Node *root){
    map<int,vector<int>> mp;
    queue<pair<Node*,int>> q;
    // traverse tree in Level Order Traversal and push element in map
    q.push({root,0});
    while(!q.empty()){
        pair<Node*,int> p=q.front();
        q.pop();
        Node *curr=p.first;
        int hd=p.second;
        mp[hd].push_back(curr->key);
        if(curr->left) q.push({curr->left,hd-1});
        if(curr->right) q.push({curr->right,hd+1});
    }
    // print vTraversal from map
    for(auto &it: mp){
        for(int &el: it.second){
            cout << el << " ";
        }
        cout << endl;
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    vTraversal(root);
    return 0;
}