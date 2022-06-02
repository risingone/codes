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

// M-1 using stack and queue
void printSpiral(Node* root){
    if(root==NULL) return;
    stack<int> s;
    queue<Node *> q;
    // we toggle it
    bool reverse=false;
    q.push(root);
    // we modify level order line by line
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node *curr=q.front();
            q.pop();
            // if reverse is true we push values in stack and print later in rev order
            if(reverse){
                s.push(curr->key);
            }
            // else we print normally
            else{
                cout << curr->key << " ";
            }
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        // print in reverse order
        if(reverse){
            while(!s.empty()){
                cout << s.top() << " ";
                s.pop();
            }
        }
        reverse=!reverse; // toggle
        cout << endl;
    }
}

// M-2 using 2 stack's
void printSpiral2(Node *root){
    stack<Node*> s1,s2;
    // push root to the stack s1.
    s1.push(root);
    // while any of the 2 stacks is not empty
    while(!s1.empty() || !s2.empty()){
        // while s1 is not empty
        while(!s1.empty()){
            // take out a node and print it
            Node *curr = s1.top();
            s1.pop();
            cout << curr->key << " ";
            // push its children L->R in s2
            if(curr->left) s2.push(curr->left);
            if(curr->right) s2.push(curr->right);
        }
        cout << endl;
        // while s2 is not empty
        while(!s2.empty()){
            // take out a node and print it
            Node *curr = s2.top();
            s2.pop();
            cout << curr->key << " ";
            // push its children R->L in s1
            if(curr->right) s1.push(curr->right);
            if(curr->left) s1.push(curr->left);
        }
        cout << endl;
    }
}

int main(){
    Node *root=new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->left->left = new Node(60);
    root->right->left->right = new Node(70);
    root->right->right->right = new Node(80);
    // 10 -> 30 20 -> 40 50 -> 80 70 60 
    printSpiral(root);
    printSpiral2(root); 
    return 0;
}