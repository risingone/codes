/*To get largest Element in an Array*/
#include <bits/stdc++.h>
using namespace std;
int getLargest(int arr[],int n){ // O(n)
    int res=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[res]) res=i;
    }
    return res;
}

int secLargest(int arr[],int n){ // naive approach
    int largest = getLargest(arr,n); // first get index of largest element
    int res = -1;
    for(int i=0;i<n;i++){
        if(arr[i] != arr[largest]){
            if(res == -1) res=i;
            else if(arr[i] > arr[res]) res=i; // get index of second largest element
        }
    }
    return res; // return -1 if it doesn't exist
}

int effsecLargest(int arr[], int n){
    int res=-1,largest=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[largest]){ //a[i]>a[largest] : res=largest
            res = largest;       
            largest = i;
        }                        // a[i]==a[largest] : ignore
        else if(arr[i] != arr[largest]){      //if a[i] < a[largest] then
            if(res=-1 || arr[i] > arr[res]){  //1)res == -1 : res=i
                res = i;                      //2)a[i]<=a[res] : ignore
            }                                 //3)a[i]>a[res] : res=i
        }
    }
    return res;
}
int main(){
    int A[] = {5,8,20,10};
    int n = getLargest(A,4);
    int sec = secLargest(A,4);
    int effsec = effsecLargest(A,4);
    cout << "Largest element: " << A[n] << endl;
    cout << "Second Largest element: " << A[sec] << endl;
    cout << "Second Largest element: " << A[effsec] << endl;
    return 0;
}