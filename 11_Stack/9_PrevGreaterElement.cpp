#include<bits/stdc++.h>
using namespace std;

// Naive Solution O(n^2)
void printPrevGreater(int arr[],int n){
    for(int i=0;i<n;i++){
        int j;
        for(j=i-1;j>=0;j--){
            if(arr[j]>arr[i]){
                cout << arr[j] << " ";
                break;
            }
        }
        if(j==-1){
            cout << -1 << " ";
        }
    }
    cout << endl;
}

// efficient Solution O(n)
void printPrevGreater1(int arr[],int n){
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()<=arr[i])
            s.pop();
        int prevGreater = s.empty()?-1:s.top();
        cout << prevGreater << " ";
        s.push(arr[i]);
    }
    cout << endl;
}

int main(){
    int n=5;
    int arr[]={20,30,10,5,15};
    printPrevGreater(arr,n);
    printPrevGreater1(arr,n);
    return 0;
}