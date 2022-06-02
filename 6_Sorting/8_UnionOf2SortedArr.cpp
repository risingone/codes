#include<bits/stdc++.h>
using namespace std;
// naive O(m+n)*log(m+n)
void printUnion(int a[],int b[],int m,int n){
    int c[m+n];  // to sore a[]+b[]
    for(int i=0;i<m;i++){
        c[i]=a[i];
    }
    for(int j=0;j<n;j++){
        c[m+j]=b[j];
    }
    sort(c,c+m+n);  // sort the array
    for(int i=0;i<(m+n);i++){
        if(i==0||c[i]!=c[i-1]){
            cout << c[i] << " "; //print distinct elements
        }
    }
}

// efficient approach
void effprintUnion(int a[],int b[],int m,int n){
    int i=0,j=0;
    while(i<m && j<n){
        if(i>0 && a[i]==a[i-1]){i++; continue;}        // skip repeating elements
        if(j>0 && b[j]==b[j-1]){j++; continue;}        
        if(a[i]<b[j]){ cout << a[i] <<" ";i++;}        // print elements in sorted fashion
        else if(b[j]<a[i]){ cout << b[j] <<" ";j++;}
        else{
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    while(i<m){                                       // print remaining elements
        if(i==0||a[i]!=a[i-1]) cout << a[i] << " ";   // edge case i==0, if both arr are completely distinct
        i++;
    }
    while(j<n){
        if(j==0||b[j]!=b[j-1]) cout << b[j] << " ";
        j++;
    }
}

int main(){
    int a[]={10,20,20};
    int b[]={5,20,40,40};
    printUnion(a,b,3,4);
    cout << endl;
    effprintUnion(a,b,3,4);
    return 0;
}