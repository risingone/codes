#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next =NULL;
    }
};

struct TreeNode{
    int data;
    TreeNode *left,*right;
    TreeNode(int x){
        data = x;
        left=right=NULL;
    }
};

// iterative inorder
void inorder(TreeNode *root){
    stack<TreeNode*> st;
    TreeNode* curr=root;
    while(curr!=NULL||!st.empty()){
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout << curr->data << " ";
        curr=curr->right;
    }
}

// function to make BT from LL
void convert(Node *head, TreeNode *&root) {
    // Your code here
    if(head==NULL) return;
    queue<TreeNode*> q;
    root = new TreeNode(head->data);
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(head->next){
            curr->left = new TreeNode(head->next->data);
            q.push(curr->left);
            head=head->next;
        }
        if(head->next){
            curr->right = new TreeNode(head->next->data);
            q.push(curr->right);
            head=head->next;
        }
    }
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    TreeNode* root=NULL;
    convert(head,root);
    inorder(root); 
    return 0;
}