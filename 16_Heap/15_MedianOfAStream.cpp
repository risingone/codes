#include<bits/stdc++.h>
using namespace std;
// Naive Method
void calMedian(int arr[],int &n){
    double temp[n];
    int size=0;
    for(int i=0;i<n;i++){
        temp[i]=arr[i];
        size++;
        int j=i;
        while(j>0 && temp[j]<temp[j-1]){
            swap(temp[j],temp[j-1]);
            j--;
        }
        if(size%2!=0){   // if size is odd
            cout << temp[size/2] << " ";
        } else{
            cout << (temp[size/2]+temp[(size-1)/2])/2 << " ";
        }
    }
    cout << endl;
}

void printMedians(int arr[],int n){
    priority_queue<int> s; // max head
    priority_queue<int, vector<int>,greater<int>> g; // min head
    s.push(arr[0]);
    cout << arr[0] << " ";
    for(int i=1;i<n;i++){
        int x=arr[i];
        if(s.size()>g.size()){ // in case s has 1 extra element than g
            if(s.top()>x){    // if x < s.top()
                g.push(s.top()); // we shift maxm element of a into g
                s.pop();         // and insert x into s
                s.push(x);
            } else g.push(x);   // otherwise simply push into g
            cout << (s.top()+g.top())/2.0 << " "; // as there will be = elements in s and g(total element even)
        } else{  // when both have = size, we have to insert extra element into s
            if(x<=s.top()){ // if x<= s's maxm element, simply add it
                s.push(x);
            } else{         // otherwise , 
                g.push(x);  // we push x into g and get minm. element of g
                s.push(g.top()); // and push it into s
                g.pop();
            }
            cout << s.top() << " "; // as s has 1 element greater
        }
    }
    cout << endl;
}

int main(){
    int arr[] = {25,7,10,15,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    calMedian(arr,n);
    printMedians(arr,n);
    return 0;
}