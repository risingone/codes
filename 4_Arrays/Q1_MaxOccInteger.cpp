#include<bits/stdc++.h>
using namespace std;

int maxOccured(int L[], int R[], int n, int maxx){
        // take array of size maxx+1 with 0's in it 
        int arr[maxx+1] = {0};
        // add 1 to indices where range begin
        for(int i=0;i<n;i++){
            arr[L[i]] += 1;
        }
        // add -1 to ind+1 where range end
        for(int i=0;i<n;i++){
            if(R[i]!=maxx){
                arr[R[i]+1] +=-1;
            }
        }
        int mx=arr[0],res=0;
        // take prefix Sum as it give occ. of each ele.
        for(int i=1;i<=maxx;i++){
            arr[i] += arr[i-1];
            if(arr[i]>mx){
                mx=arr[i];
                res=i;
            }
        }
        return res;
}

int main(){
    int n=4;
    // 1,2,3,4,........14,15
    // 4,5,6,7,8
    // 3,4,5
    // 1,2,3,4
    int L[]={1,4,3,1};
    int R[]={15,8,5,4};
    int maxx=15;
    cout << maxOccured(L,R,n,maxx) << endl;
    return 0;
}