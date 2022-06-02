/*To return index of element which occurs more the half the no. of elements in the array
e.g: arr[] = {8,3,4,8,8} =) 0 or 3 or 4*/
#include<bits/stdc++.h>
using namespace std;
// M-1 naive approach O(n^2)
int findMajority(int arr[],int n){
    for(int i=0;i<n;i++){         // for each element count its occurrence
        int count=1;
        for(int j=i+1;j<n;j++){  
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>n/2){           // if its occurence are > n/2 return its index
            return i;
        }
    }
    return -1;     //if majority element doesn't exists
}
// M-2 efficient approach O(n)
int findMajority2(int arr[],int n){
    int res=0,count=1;
    /*important: to be remembered*/
    // find majority elem.
    for(int i=1;i<n;i++){ // to find suitable element
        if(arr[res]==arr[i]) count++;
        else
            count--;
        if(count==0) {
            res=i;
            count=1;
        }
    }
    count=0;
    // check if majority ele. actually exist
    for(int i=0;i<n;i++){    // to calculate freq. of suitable element
        if(arr[res]==arr[i]){
            count++;
        }
    }
    if(count<=n/2) res=-1;
    return res;
}
int main(){
    int A[]={8,7,6,8,6,6,6,6};
    cout << findMajority(A,8) << endl;// it will give index for first occurence
    cout << findMajority2(A,8) << endl;// in it index might be returned for any occurence
    return 0;
}