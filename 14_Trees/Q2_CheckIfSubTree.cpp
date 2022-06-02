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

class Solution
{
    // we use is same to compare
    bool isSame(Node *a,Node *b){
        if(a==NULL||b==NULL) return a==b;
        return (a->data==b->data)&&isSame(a->left,b->left)&&isSame(a->right,b->right);
    }
  public:
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        if(T==NULL) return false;
        // handle edge case if data matches but isSame() return false, keep on calling
        // subtree as there can still be a possiblity
        if(T->data==S->data) return isSame(T,S)||(isSubTree(T->left,S)||isSubTree(T->right,S));
        return (isSubTree(T->left,S)||isSubTree(T->right,S));
    }
};

int main(){
    Solution s;
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->right->left = new Node(4);
    Node *root2 = new Node(3);
    root2->left = new Node(4);
    cout << s.isSubTree(root1,root2) << endl;
    return 0;
}