#include<bits/stdc++.h>
using namespace std;
struct Interval{
    int st;
    int end;
};
bool myComp(Interval a,Interval b){ //function to define the way of sorting
    return a.st<b.st;
}
void mergeIntervals(Interval arr[], int n){
    sort(arr,arr+n,myComp);   // sort the array
    int res=0;
    for(int i=1;i<n;i++){  // traverse the arr
        if(arr[res].end>=arr[i].st){ // if intervals overlap merge them
            arr[res].end = max(arr[res].end,arr[i].end);
            arr[res].st = arr[res].st;
        } else{                      // else move to next element
            res++;
            arr[res]=arr[i];
        }
    }
    for(int i=0;i<=res;i++){
        cout << arr[i].st << " " << arr[i].end << endl;
    }
}
int main(){
    Interval arr[]={{1,3},{2,4},{5,7},{6,8}};
    mergeIntervals(arr,4);
    return 0;
}