/*To calculate total amount of rain water which could be trapped b/w blocks of different sizes*/
#include<bits/stdc++.h>
using namespace std;
//M-1 naive approach
int getWater(int arr[],int n){
    int res=0;
    for(int i=1;i<n-1;i++){
        int lmax = arr[i];
        for(int j=0;j<i;j++){  // to calculate max. element on left
            lmax=max(lmax,arr[j]);
        }
        int rmax=arr[i];
        for(int j=i+1;j<n;j++){ // to calculate max. element on right
            rmax=max(rmax,arr[j]);
        }
        res += (min(lmax,rmax)-arr[i]); // for ith element min. of lmax & rmax - arr[i] water can be stored
    }
    return res;
}
//M-2, use lmax array & rmax array to save time
int getWater2(int arr[],int n){
    int res=0;
    int lMax[n],rMax[n];
    lMax[0]=arr[0];
    for(int i=1;i<n;i++){
        lMax[i] = max(arr[i],lMax[i-1]); // lMax[] = {5,5,6,6,6}
    }
    rMax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        rMax[i] = max(arr[i],rMax[i+1]); // rMax[] = {6,6,6,3,3}
    }
    for(int i=1;i<n-1;i++){
        res += min(lMax[i],rMax[i])-arr[i]; //water stored over each element except 0 & n-1th
    }
    return res;
}
int main(){
    int arr[]={5,0,6,2,3};
    cout << getWater(arr,5) << endl;
    cout << getWater2(arr,5) << endl;
    return 0;
}