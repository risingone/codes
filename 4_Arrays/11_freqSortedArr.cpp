/*To calculate frequency of each element in a sorted array*/
#include<bits/stdc++.h>
using namespace std;
//M-1
void freq(int arr[],int n){ // own implementation O(n)
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            count++;
        }
        else{
            cout << arr[i-1] <<" -> " << count << endl;
            count=1;
        }
    }
    cout << arr[n-1] <<" -> " << count << endl;
}
//M-2
void printFreq(int arr[],int n){
    int freq=1,i=1;
    while(i<n){
        while(i<n && arr[i]==arr[i-1]){
            freq++;
            i++;
        }
        cout << arr[i-1] << " : " << freq << endl;
        i++;
        freq=1;
    }
    if(n==1 || arr[n-1]!=arr[n-2]){
        cout << arr[n-1] << " : " << 1 << endl; 
    }
}
int main(){
    int A[] = {10,10,10,20,30,30};
    freq(A,6);
    printFreq(A,6);
    return 0;
}