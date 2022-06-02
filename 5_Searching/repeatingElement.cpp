/*Find repeating element in an Array
Given: a)Array Size, n>=2
       b)Only one Element Repeats(any number of times)
       c)All the elements from 0 to max(arr) are present
    Therefore 0<= max(arr) <=n-2*/
#include<bits/stdc++.h>
using namespace std;
//super naive method will be O(n^2)-> we will check for each element if it exists more than once
// M-1 Naive approach: O(nlog n) time & O(1) space
int repeatedEle(int arr[],int n){
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            return arr[i];
        }
    }
    return -1;
}
//M-2: O(n) time and O(n) space
int repeatedEle2(int arr[],int n){
    bool visited[n]={false};
    for(int i=0;i<n;i++){
        if(visited[arr[i]]) return arr[i]; // when element appears 2nd time it return the element
        visited[arr[i]] = true;
    }
    return -1;
}
//M-3: O(n) time and O(1) space
int findRepeating(int arr[],int n){
    int slow=arr[0]+1,fast=arr[0]+1; // we modify content of all arr. ele by +1 to avoid infinite loop
                                     // e.g: {0,...} or{1,0,....}
    do {                             // Phase-1 -> to get a common element in cycle at x dist from 1 ele.
        slow = arr[slow]+1;          // 1) Fast will enter the cycle First(or at same time)
        fast = arr[arr[fast]+1]+1;   // 2) In every iteration, distance increases by 1
    }while(slow != fast);            // as fast already moved k ele. ahead when slow entered
                                     // so on every exec. we move k+1 in cycle
    slow=arr[0]+1;            // Phase-2: we get repeated ele. as (m+x) is a multiple of c
    while(slow!=fast){        // where m is no of elem. ahead from slow cycle begin, c is elem. in cycle
        fast = arr[fast]+1;   // so when both move m times 
        slow = arr[slow]+1;   // both reach at start of cycle(repeated elem.)
    }
    return slow-1;
}
int main(){
    int A[] = {1,2,3,0,3,4,5};
    int n=sizeof(A)/sizeof(A[0]);
    // cout << repeatedEle(A,n) << endl;
    cout << repeatedEle2(A,n) << endl;
    cout << findRepeating(A,n) << endl;
    return 0;
}