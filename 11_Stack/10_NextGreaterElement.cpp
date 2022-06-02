#include<bits/stdc++.h>
using namespace std;

// naive O(n^2)
void printNextGreater(int arr[],int n){
    for(int i=0;i<n;i++){
        int j;
        for(j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                cout << arr[j] << " ";
                break;
            }
        }
        if(j==n){
            cout << -1 << " ";
        }
    }
    cout << endl;
}

// efficient O(n)
vector<int> nextGreater(int arr[],int n){
    vector<int> v;
    stack<int> s;
    s.push(arr[n-1]);
    v.push_back(-1);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i])
            s.pop();
        int nG = s.empty()?-1:s.top();
        v.push_back(nG);
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}

int main(){
    int n=8;
    int arr[]={5,15,10,8,6,12,9,18};
    printNextGreater(arr,n);
    vector<int> res = nextGreater(arr,n);
    for(int x: res){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}