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

// M-1 Store Inorder traversal of elements in a array
void inorder(Node *root,vector<int> &v){
    if(root==NULL) return;
    inorder(root->left,v);
    v.push_back(root->key);
    inorder(root->right,v);
}

// M-2: Modifying inorder traversal
bool isPairSum(Node *root,int sum,unordered_set<int> &s){
    if(root==NULL) return false;
    if(isPairSum(root->left,sum,s)) return true;
    if(s.find(root->key)!=s.end()) return true;
    else s.insert(sum-root->key);
    return isPairSum(root->right,sum,s);
}

int main(){
    int sum=33;
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(20);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);
    root->right->right->left = new Node(25);
    // M-1
    vector<int> v;
    inorder(root,v);
    // after getting inorder traversal we use 2ptr approach to pair with given sum
    int i=0,j=v.size()-1;
    while(i<j){
        if(v[i]+v[j]==sum){
            break;
        }
        if((v[i]+v[j])<sum) i++;
        else j--;
    } 
    if(i<j){
        cout << "Pair with given sum is present!" << endl;
    } else{
        cout << "Not present!" << endl;
    }
    // M-2: using unordered set
    unordered_set<int> s;
    cout << isPairSum(root,sum,s) << endl;
    return 0;
}