/* Given an array consisting of page no. of books and no. of student, we have to allocate the pages to students
such that maximum pages allocated to a student will be minimum & also only contiguous pages can be allocated*/
#include<bits/stdc++.h>
using namespace std;
// M-1: using recursion
int sum(int arr[],int b,int e){ //it return sum of array from index b to e
    int s=0;
    for(int i=b;i<=e;i++){
        s += arr[i];
    }
    return s;
}
int minPages(int arr[],int n,int k){
    if(n==0) return arr[0];
    if(k==1) return sum(arr,0,n-1);
    int res=INT_MAX;
    for(int i=1;i<n;i++){
        res = min(res,max(minPages(arr,i,k-1),sum(arr,i,n-1)));  //we start dividing from end
    }
    return res;
}
// M-2
/*e.g: {10,20,10,30} k=2 -> sum=70 max=30
        x=(30 + 70)/2 = 50, res=50
        x=(30 + 49)/2 = 39, not feasible as we get req=3>k
        x=(40 + 49)/2 = 44, res=44 =) x=(40+43)/2 = 41, res=41 =) x=(40+40)/2 = 40, res=40*/
bool isFeasible(int arr[],int n,int k,int ans){
    int req=1,sum=0; //here req is total no. of students req such that each get pages<ans
    for(int i=0;i<n;i++){
        if(sum+arr[i] > ans){// when allocated pages become > ans
            req++;           // update req
            sum = arr[i];    // update sum as the new ele. will be for next student
        }
        else{
            sum += arr[i];   // otherwise keep on adding
        }
    }
    return (req <= k);  // if req<= k return true
}
int minPages2(int arr[],int n,int k){
    int sum=0,mx=0; // as answer will be in range of maxm. val & sum
    for(int i=0;i<n;i++){
        sum += arr[i];       // it stores sum of array
        mx = max(mx,arr[i]);// it stores maxm. element present in array
    }
    int low=mx,high=sum,res=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(isFeasible(arr,n,k,mid)){
            res=mid;          //if feasible go to the left half
            high=mid-1;       
        }
        else{
            low = mid+1;      //else go to the right half
        }
    }
    return res;
}
int main(){
    int arr[]={10,20,30,40};
    int n=sizeof(arr)/sizeof(arr[0]),k=2;
    cout << minPages(arr,n,k) << endl;
    cout << minPages2(arr,n,k) << endl;
    return 0;
}