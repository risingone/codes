/*Given a sorted array and a sum, find if there is a pair with given sum*/
#include<bits/stdc++.h>
using namespace std;
bool isPair(int arr[],int n,int x){
    int left=0,right=n-1;
    while(left<right){
        if((arr[left]+arr[right])==x) return true;
        else if((arr[left]+arr[right])>x){ //as sum is greater so move right ptr
            right--;
        }
        else{                              // as sum is less so move left ptr
            left++;
        }
    }
    return false;
}
int main(){
    int A[] = {2,5,8,12,30};
    int n = sizeof(A)/sizeof(A[0]);
    int x=17;
    cout << isPair(A,n,x) << endl;
    return 0;
}