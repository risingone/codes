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

class Solution
{
    Node* reverseList(Node *head){  // function to reverse a LL
        if(head==NULL||head->next==NULL) return head;
        Node *curr=head,*prev=NULL,*nex=NULL;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        int sum=0;
        int carry=0;
        first = reverseList(first);     // reverse both lists as we 
        second = reverseList(second);   // start adding from one's place
        Node *head= new Node(0);
        Node *tail = head;
        while(first&&second){           // keep on adding till one of the list is exhausted
            sum=0;
            sum = first->data + second->data + carry;
            carry=sum/10;
            sum=sum%10;
            tail->next = new Node(sum);
            tail=tail->next;
            first=first->next;
            second=second->next;
        }
        if(first!=NULL){                 // add remaing list to the resultant list 
            tail->next=first;
        }
        else{
            tail->next=second;
        }
        while(carry!=0){           // now update data till carry become 0
            if(first!=NULL){
                first->data += carry;
                carry = (first->data)/10;
                first->data %= 10;
                first=first->next;
                tail=tail->next;
            } else if(second!=NULL){
                second->data += carry;
                carry = (second->data)/10;
                second->data %= 10;
                second=second->next;
                tail=tail->next;
            } else {
                tail->next = new Node(carry);
                carry=0;
            }
        }
        return reverseList(head->next);
    }
};
 
void printList(Node* head){
    if(head==NULL) return;
    while(head){
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

int main(){
    Solution s;
    Node *head=new Node(9);
    head->next=new Node(9);
    head->next->next=new Node(9);
    head->next->next->next = new Node(9);
    printList(head);
    Node *head2=new Node(9);
    head2->next=new Node(9);
    printList(head2);
    Node* res = s.addTwoLists(head,head2);
    printList(res);
    return 0;
}