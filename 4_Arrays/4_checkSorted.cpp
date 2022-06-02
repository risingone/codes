/*To check if an Array is sorted or not*/
#include<bits/stdc++.h>
using namespace std;
bool isSorted(int arr[], int n){
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]) return false;
    }
    return true;
}
int main(){
    int A[]={5,12,30,32,35};
    bool sorted = isSorted(A,5);
    if(sorted){
        cout << "Given Array is sorted." << endl;
    }
    else{
        cout << "Given Array is not sorted." << endl;
    }
    return 0;
}