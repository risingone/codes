#include<bits/stdc++.h>
using namespace std;
int maxGuest(int arr[],int dep[],int n){
    sort(arr, arr+n);
    sort(dep, dep+n);
    int i=1,j=0,res=1,curr=1;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){ //if arr[i] < dep[j] they can meet
            curr++;
            i++;
        } else{           // else decrease curr and move forward
            curr--;
            j++;
        }
        res=max(res,curr); // update res
    }
    return res;
}
int main(){
    int arr[] = {900, 600, 700};
    int dep[] = {1000, 800, 730};
    cout << maxGuest(arr, dep, 3) << endl;
    return 0;
}