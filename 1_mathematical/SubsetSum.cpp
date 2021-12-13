/*TO count number of subsets whose sum is equal to given sum*/
#include<bits/stdc++.h>
using namespace std;
int countSubsets(int A[], int n, int sum){
    if(n==0)
        return (sum==0)?1:0; // if subsets sum is equal we get 1
    return countSubsets(A,n-1,sum) + countSubsets(A,n-1,sum-A[n-1]); // for each element there will be 2 case
}                                                                    // take element or leave element
int main(){
    int A[]={5,10,20,15};
    int sum=25;
    cout << countSubsets(A,4,sum) << endl;
    return 0;
}