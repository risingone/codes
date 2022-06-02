/*to calculate maximum consecutive 1's in an array*/
#include<bits/stdc++.h>
using namespace std;
//M-1 naive approach O(n^2)
int maxConsecutiveOnes(bool arr[],int n){
    int res=0;
    for(int i=0;i<n;i++){
        int curr=0;           // for each element
        for(int j=i;j<n;j++){ // count consequent 1s
            if(arr[j]==1) curr++;
            else break;
        }
        res = max(res,curr);  // update res if required
    }
    return res;
}
//M-2 efficient approach O(n)
int maxConsecutiveOnes2(bool arr[],int n){
    int res=0,curr=0;
    for(int i=0;i<n;i++){ // traverse through the array
        if(arr[i]==0) curr=0; // if we get 0, make curr=0
        else{                 // else update curr & acc. to it update res 
            curr++;
            res = max(res,curr);
        }
    }
    return res;
}
int main(){
    bool A[]={0,0,1,1,1,1,1,0};
    cout << maxConsecutiveOnes(A,8) << endl;
    cout << maxConsecutiveOnes2(A,8) << endl;
    return 0;
}