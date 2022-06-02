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

// M-1: TC: O(n) SC:O(vw)
void vwidth(Node *root,int w,unordered_set<int>& ust){
    if(root==NULL) return;
    if(ust.find(w)==ust.end()) ust.insert(w);
    if(root->left) vwidth(root->left,w-1,ust);
    if(root->right) vwidth(root->right,w+1,ust);
}
int verticalWidth(Node* root)
{
    // Code here
    int w=0;
    unordered_set<int> ust;
    vwidth(root,w,ust);
    return ust.size();
}

// M-2: TC: O(n) SC:O(1);
void width(Node *root,int &mx,int &mn,int curr){
    if(root==NULL) return;
    mx=max(mx,curr);
    mn=min(mn,curr);
    width(root->left,mx,mn,curr-1);
    width(root->right,mx,mn,curr+1);
}
int verticalWidth2(Node* root)
{
    // Code here
    if(root==NULL) return 0;
    int mx=0,mn=0;
    width(root,mx,mn,0);
    return 1+(mx-mn);
}

int main(){
    Node *root = new Node(10);  // w->0
    root->left = new Node(20);  // w->-1
    root->right = new Node(30); // w->1
    root->left->left = new Node(15); // w->-2
    root->left->right = new Node(25);// w->-1
    root->right->right = new Node(40);// w->2
    cout << verticalWidth(root) << endl;
    cout << verticalWidth2(root) << endl;
    return 0;
}