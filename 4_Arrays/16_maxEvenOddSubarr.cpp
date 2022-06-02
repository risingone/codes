/*To find maximum length of subarray which consist of consecutive even & odd numbers*/
#include<bits/stdc++.h>
using namespace std;
//M-1 naive approach O(n^2)
int maxEvenOdd(int arr[],int n){
    int res=1;
    for(int i=0;i<n;i++){ // for each element we cal. length
        int curr=1;
        for(int j=i+1;j<n;j++){ 
            if((arr[j]%2==0 && arr[j-1]%2!=0) || (arr[j]%2!=0 && arr[j-1]%2==0)){ //if coseq. even & odd exist
                curr++;                                                           //update curr
            }
            else{                                                                 // else break from loop
                break;
            }
        }
        res = max(res,curr);    // upadate res if curr>res
    }
    return res;
}
//M-2 more efficient O(n)
int maxEvenOdd2(int arr[],int n){
    int res=1,curr=1;
    for(int i=1;i<n;i++){ //we traverse through the loop
        if((arr[i]%2==0 && arr[i-1]%2!=0)||(arr[i]%2!=0 && arr[i-1]%2==0)){ //if we get conseq. even & odd
            curr++;                                                         // update curr
            res = max(res,curr);                                            // updater res if curr>res
        }
        else{          // if there appear 2 consq. even or odd
            curr=1;    // make curr=1
        }
    }
    return res;
}
int main(){
    int A[]={5,10,20,6,3,8,5};
    cout << maxEvenOdd(A,7) << endl;
    cout << maxEvenOdd2(A,7) << endl;
    return 0;
}