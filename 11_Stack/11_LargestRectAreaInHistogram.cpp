#include<bits/stdc++.h>
using namespace std;

// M-1: naive
int getMaxArea(int arr[],int n){
    int res=0;
    for(int i=0;i<n;i++){
        int curr = arr[i];
        for(int j=i-1;j>=0;j--){
            if(arr[j]>=arr[i]) curr += arr[i];
            else break;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j]>=arr[i]) curr += arr[i];
            else break;
        }
        res = max(res,curr);
    }
    return res;
}

// M-2: efficient
// it return vector with indices of consq. previous smaller element
vector<int> getps(int arr[],int n){
    vector<int> v;
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()]>=arr[i])
            s.pop();
        int prevSmall = s.empty()?-1:s.top();
        v.push_back(prevSmall);
        s.push(i);
    }
    return v;
}
// it return vector with indices of consq. next smaller element
vector<int> getns(int arr[],int n){
    vector<int> v;
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[s.top()]>=arr[i])
            s.pop();
        int nextSmall = s.empty()?n:s.top();
        v.push_back(nextSmall);
        s.push(i);
    }
    reverse(v.begin(),v.end());
    return v;
}
int getMaxArea1(int arr[],int n){  // 6 2 5 4 1 5 6
    int res=0,curr=0;
    vector<int> ps = getps(arr,n); // -1 -1 1 1 -1 4 5
    vector<int> ns = getns(arr,n); // 1 4 3 4 7 7 7
    for(int i=0;i<n;i++){
        curr = arr[i];
        curr += (i-ps[i]-1)*arr[i];
        curr += (ns[i]-i-1)*arr[i];
        res = max(res,curr);
    }
    return res;
}

// M-3: Most Efficient Approach
int getMaxArea2(int arr[],int n){
    int res=0,curr,tp;
    stack<int> s;
    // this part take cares of all element for which ith ele. is next smaller
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()]>=arr[i]){
            tp=s.top();
            s.pop();
            curr = arr[tp]*(s.empty()?i:(i-s.top()-1));
            res = max(res,curr);
        }
        s.push(i);
    }
    // this part takes care of ele. for which next smaller is not present in array
    // and they are still present in stack
    while(!s.empty()){
        tp = s.top();
        s.pop();
        curr = arr[tp]*(s.empty()?n:(n-s.top()-1));
        res = max(res,curr);
    }
    return res;
}

int main(){
    int n=7;
    int arr[] = {6,2,5,4,1,5,6};
    cout << getMaxArea(arr,n) << endl;
    cout << getMaxArea1(arr,n) << endl;
    cout << getMaxArea2(arr,n) << endl;
    return 0;
}