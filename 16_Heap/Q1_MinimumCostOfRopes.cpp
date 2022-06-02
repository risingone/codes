/*here are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.
Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29
Explanation:
For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can
connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
2) Now connect ropes of lengths 4 and 5.Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all ropes have connected.
Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three strings of 3, 2 and 10), then connect 10 and 3 (we get two strings of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long minCost(long long arr[], long long n){
        priority_queue<long long,vector<long long>,greater<long long>> pq(arr,arr+n); // push all array
        long long ans=0;                                          // elements into the min Heap O(n)
        while(pq.size()>1){ // keep on adding 2 minm ropes length until there is
            long long curr=pq.top(); // onlu 1 rope in the heap
            pq.pop();
            curr += pq.top();
            pq.pop();
            pq.push(curr);
            ans += curr;
        }
        return ans;
    }
};

int main(){
    Solution s;
    long long arr[]={4, 3, 2, 6};
    long long n = 4;
    cout << s.minCost(arr,n) << endl;
    return 0;
}