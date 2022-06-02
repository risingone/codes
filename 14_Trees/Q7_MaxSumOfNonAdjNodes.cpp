#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};

class Solution{
    // for using memoization
    unordered_map<Node*,int> ump;
  public:
    int getMaxSum(Node *root) 
    {
        // for each node we have 2 choice take it or leave it
        // if we take it we can't take it's children, we have to take its grand children only
        // else we can
        if(root==NULL) return 0;
        if(ump.find(root)!=ump.end()) return ump[root];
        int a=root->data,b=0; // a->we take node, b-> we don't
        if(root->left){
            a+=getMaxSum(root->left->left);
            a+=getMaxSum(root->left->right);
            b+=getMaxSum(root->left);
        }
        if(root->right){
            a+=getMaxSum(root->right->left);
            a+=getMaxSum(root->right->right);
            b+=getMaxSum(root->right);
        }
        ump[root]=max(a,b);
        return ump[root];
    }
};

int main(){
    Solution s;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    cout << s.getMaxSum(root) << endl;
    return 0;
}