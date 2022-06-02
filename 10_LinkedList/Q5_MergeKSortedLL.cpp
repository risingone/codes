#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* sortedMerge(Node* a, Node* b){
    if(a==NULL) return b;    // if one of the LL
    if(b==NULL) return a;    // is NULL return other
    Node *head = NULL,*tail=NULL;
    if(a->data<b->data){    // initialize head and tail
        head=tail=a;
        a=a->next;
    }
    else{
        head=tail=b;
        b=b->next;
    }
    while(a!=NULL && b!=NULL){
        if(a->data<=b->data){
            tail->next=a;
            tail=a;
            a=a->next;
        }
        else{
            tail->next = b;
            tail = b;
            b = b->next;
        }
    } // if one of the LL exhausts link rest of the other LL
    if(a==NULL) tail->next = b;
    else tail->next = a;
    return head; // return head of the new LL
}
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           if(K==1){
               return arr[0];
           }
           if(K==2){
               return sortedMerge(arr[K-1],arr[K-2]);
           } 
           arr[K-2]=sortedMerge(arr[K-1],arr[K-2]);
           return mergeKLists(arr,K-1);
    }
};

void printList(Node *head){
    if(head==NULL) return;
    while(head){
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

int main(){
    Solution s;
    Node* ll1 = new Node(1); // 1 3 5
    ll1->next = new Node(3);
    ll1->next->next = new Node(5);
    Node* ll2 = new Node(4); // 4 7 11
    ll2->next = new Node(7);
    ll2->next->next = new Node(11);
    Node *ll3 = new Node(2); // 2 6
    ll3->next = new Node(6);
    int K=3;
    Node* arr[K]={ll1,ll2,ll3};
    Node* head = s.mergeKLists(arr,K);
    printList(head);
    return 0;
}