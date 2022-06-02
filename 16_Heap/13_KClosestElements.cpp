#include<bits/stdc++.h>
using namespace std;

// M-1 Naive: TC: O(nk) SC: O(n)
void printkClose(int arr[],int &n,int &k,int &x){
    bool visited[n] = {false};
    for(int i=0;i<k;i++){
        int min_diff = INT_MAX,min_diff_idx;
        for(int j=0;j<n;j++){
            if(!visited[j]&&abs(arr[j]-x)<=min_diff){
                min_diff = abs(arr[j]-x);
                min_diff_idx=j;
            }
        }
        cout << arr[min_diff_idx] << " ";
        visited[min_diff_idx] = true;
    }
    cout << endl;
}

// M-2 Efficient O(klogk + (n-k)*logk + klogk)
void printkClose2(int arr[],int &n,int &k,int &x){
    priority_queue<pair<int,int>> pq; // pair of abs(diff) and index of element
    for(int i=0;i<k;i++){ // push pair for 1st k elements
        pq.push({abs(arr[i]-x),i});
    }
    // we traverse the array and if we see element 
    // with diff < pq.top().diff we pop out top element and push current element
    for(int i=k;i<n;i++){
        int diff=abs(arr[i]-x);
        if(pq.top().first>diff){
            pq.pop();
            pq.push({diff,i});
        }
    }
    for(int i=0;i<k;i++){
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
    cout << endl;
}

int main(){
    int arr[] = {10,30,5,40,38,80,70};
    int x=35,k=3,n=sizeof(arr)/sizeof(arr[0]);
    printkClose(arr,n,k,x);
    printkClose2(arr,n,k,x);
    return 0;
}