#include<bits/stdc++.h>
using namespace std;

int main(){
    // Binary Search STL
    int N=5;
    int A[] = {1,4,5,8,9};
    bool res = binary_search(A,A+N,3);  // 0
    cout << res << endl;
    res = binary_search(A,A+N,4); // 1
    cout << res << endl;

    // Lower Bound
    cout << "lower_bound" << endl;
    int n=6;
    int a[] = {1,4,5,6,9,9};
    // we use - a as we get iterator pointing to ele.
    int ind = lower_bound(a, a+n, 4) - a; // if ele. is present we get its index
    cout << ind << endl;
    cout << lower_bound(a, a+n, 7) - a << endl; // if ele. is not present we get index of ele. 
    cout << lower_bound(a, a+n, 10) - a << endl; // immediate greater than ele. we search for

    // Q-1 Find first occ. of a X in a sorted array. If it does not exist, print -1
    cout << "...............Q..............." << endl;
    int len = 9;
    int arr1[] = {1,4,4,4,4,9,9,10,11};
    int X=9;
    int index = lower_bound(arr1,arr1+len,X) - arr1;
    if(index != len && arr1[index]==X){
        cout <<index << endl;
    }
    else{
        cout << -1 << endl;
    }
    // Q-2 Find last occ. of X "  "  "  "
    // we know that upper_bound always points to next greater occ of X
    index = upper_bound(arr1,arr1+len,X) - arr1;
    index--; // as it points to next. greater ele.
    if(index>=0 && arr1[index]==X){
        cout << index << endl;
    }
    else{
        cout << -1 << endl;
    }
    // Q-3 Find largest number smaller than X in a sorted array
    index = lower_bound(arr1,arr1+len,X)-arr1;
    index--;
    if(index>=0){
        cout << arr1[index] << endl;
    }
    else{
        cout << -1 << endl;
    }
    // Q-4 Find the smallest number greater than X
    index = upper_bound(arr1,arr1+len,X) - arr1;
    if(index<len){
        cout << arr1[index] << endl; 
    }
    else{
        cout << -1 << endl;
    }
    return 0; 
}