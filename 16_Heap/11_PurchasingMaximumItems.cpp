/*To find maxm items we can buy with given sum from cost array*/
#include<bits/stdc++.h>
using namespace std;

// M-1 Sorting and select from begining O(nlogn)

//M-2 Using Heap O(n+cnt*logn)
int purchaseMax(int cost[],int &n,int sum){
    int cnt=0;
    // O(n) operation as we call builldheap
    priority_queue<int,vector<int>,greater<int>> pq(cost,cost+n);
    // O(cnt*logn) , as we only take out cnt items
    while(true){
        sum -= pq.top();
        pq.pop();
        if(sum>=0){
            cnt++;
        } else{
            break;
        }
    }
    return cnt;
}

int main(){
    int cost[] = {1,12,5,111,200};
    int sum=10,n=sizeof(cost)/sizeof(cost[0]);
    cout << purchaseMax(cost,n,sum) << endl;
    return 0;
}