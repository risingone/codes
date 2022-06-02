/*Count pairs with given sum*/
#include<bits/stdc++.h>
using namespace std;
int countPair(int arr[],int n,int x){
    int left=0,right=n-1,count=0;
    while(left<right){
        if(arr[left]+arr[right] == x){
            count++;
            left++;
            right--;
        }
        else if((arr[left]+arr[right])<x){
            left++;
        }
        else{
            right--;
        }
    }
    return count;
}
int main(){
    int A[]={1,3,5,6,7,8,9};//in case of unsorted we could sort or use hashmaps
    int n = sizeof(A)/sizeof(A[0]);
    int x=10;
    cout << countPair(A,n,x) << endl;
    return 0;
}