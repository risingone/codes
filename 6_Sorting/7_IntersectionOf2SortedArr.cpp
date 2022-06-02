/*We have to find intersection =) common elements in 2 sorted arrays*/
#include<bits/stdc++.h>
using namespace std;
// naive approach O(m*n)
void intersection(int a[], int b[], int m, int n){
    for(int i=0;i<m;i++){                  // we traverse through arr a
        if(i>0 && a[i]==a[i-1]) continue;  // for same element we exec. code once only
        for(int j=0;j<n;j++){              // we printan element if it is common in both
            if(a[i]==b[j]){
                cout << a[i] << " ";
                break;
            }
        }
    }
}

// efficient solution O(m+n)
void effintersection(int a[],int b[], int m, int n){
    int i=0,j=0;
    while(i<m && j<n){                           // traverse while one of the array gets exhausted 
        if(i>0 && a[i]==a[i-1]){i++; continue;}  // skip for same element
        if(a[i]<b[j]){i++;}                     
        else if(a[i]>b[j]){j++;}
        else{
            cout << a[i] <<" ";                 // print when a[i]==b[j]
            i++;
            j++;
        }
    }
}

int main(){
    int a[] = {1,20,20,40,60};
    int b[] = {2,20,20,20};
    intersection(a,b,5,4);
    cout << endl;
    effintersection(a,b,5,4);
    return 0;
}