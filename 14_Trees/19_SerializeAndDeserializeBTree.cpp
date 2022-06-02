#include<bits/stdc++.h>
using namespace std;
const int EMPTY=-1;

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
}

// we serialize in pre-order, and store EMPTY when NULL is enconutered
void serialize(Node *root,vector<int> &arr){
    if(root==NULL){
        arr.push_back(EMPTY);
        return;
    }
    arr.push_back(root->key);
    serialize(root->left,arr);
    serialize(root->right,arr);
}

// deserializing arr
Node *deSerialize(vector<int> &arr,int &index){
    if(index==arr.size()) return NULL;
    int val = arr[index];
    index++;
    if(val==EMPTY) return NULL;
    Node *root = new Node(val);
    root->left = deSerialize(arr,index);
    root->right = deSerialize(arr,index);
    return root;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    vector<int> arr;
    serialize(root,arr);
    for(auto &it: arr){
        cout << it << " ";
    }
    cout << endl;
    int index=0;
    Node *res = deSerialize(arr,index); 
    inorder(root);
    return 0;
}