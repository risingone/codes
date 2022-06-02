/*To  find number of consq. smaller or equal element including element itself which are present before element
 e.g: [18,12,13,14,11,16] -> [1,1,2,3,1,5]*/
#include<bits/stdc++.h>
using namespace std;

// M-1 Naive Solution O(n^2)
void printSpan(int arr[],int n){
    for(int i=0;i<n;i++){
        int span=1;
        for(int j=i-1;j>=0&&arr[j]<=arr[i];j--)
            span++;
        cout << span << " ";
    }
    cout << endl;
}

// M-2Efficient Solution O(n)

void printSpan1(int arr[],int n){
    stack<int> s;
    s.push(0);       // store and print 1 element
    cout << 1 << " ";
    for(int i=1;i<n;i++){
        while(!s.empty() && arr[s.top()]<=arr[i]){
            s.pop();
        }
        int span = s.empty()?i+1:i-s.top(); // if stack become empty return i+1
        cout << span << " ";                // else return i-s.top()
        s.push(i);
    }
    cout << endl;
}

int main(){
    int n=6;
    int arr[] = {18,12,13,14,11,16};
    printSpan(arr,n);
    printSpan1(arr,n);
    return 0;
}