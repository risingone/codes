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
// M-1 TC-O(m+n) SC-O(n)
void intersectionPt(Node* head1,Node* head2){
    unordered_set<Node*> ust;
    while(head1){ // traverse first list and put references of all the nodes
        ust.insert(head1);  // in a hashmap
        head1 = head1->next;
    }
    while(head2){  // traverse 2 list and if we find reference of any of its node
        if(ust.find(head2)!=ust.end()){ // present into hashmap, print its data and return
            cout << head2->data << endl;
            return;
        }
        head2 = head2->next;
    }
}

// M-2
int intersecPt(Node* head1,Node* head2){
    int c1=0,c2=0;
    Node* curr=head1,*curr2=NULL;
    while(curr){  // count len. of 1 LL
        c1++;
        curr=curr->next;
    }
    curr=head2;
    while(curr){ //count len. of 2 LL
        c2++;
        curr=curr->next;
    }
    // cout << c1 << " " << c2 << endl;
    if(c1>=c2) {               
        curr=head1;           // make curr point to head of longer LL
        curr2=head2;          // and curr2 point to head of shorter LL
    }
    else{
        curr=head2;
        curr2=head1;
    }
    for(int i=0;i<abs(c1-c2);i++){  // make curr point to abs(c1-c2)th node
        curr = curr->next;
    }
    while(curr!=NULL && curr2!=NULL){ // now move curr & curr2 together by 1 step at a time
        if(curr==curr2){
            return curr->data;        // if both LL intersect they will meet at the first comm. node
        }
        curr=curr->next;
        curr2=curr2->next;
    }
    return -1;                        // else return -1
}

// M-3
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int cnt1=0,cnt2=0;
    Node *p=head1,*q=head2;
    // traverse while p!=q
    while(p!=q){    // use 2 ptr to traverse LL
        if(p==NULL){    // if 1 LL ptr reach to NULL first time
            if(cnt1==0){  // make it point to 2's head
                p=head2;
                cnt1++;
            }
            else{      // else return -1
                return -1;
            }
        }
        if(q==NULL){
            if(cnt2==0){ // similarly when 2 LL ptr reach NULL
                q=head1; // make it to point to 1's head
                cnt2++;
            }
            else{
                return -1;
            }
        }
        p=p->next;
        q=q->next;
    }
    if(p==q && p!=NULL) return p->data;
    return -1;
}

int main(){
    Node* head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(12);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(5); // 17 15 8 12 10 5
    Node* head2 = new Node(11); // 11 and its next point to 12
    head2->next = head->next->next->next; // 11 12 10 5
    intersectionPt(head,head2);
    cout << intersecPt(head,head2) << endl;
    cout << intersectPoint(head,head2) << endl;
    return 0;
}