#include<bits/stdc++.h>
using namespace std;

// naive approach O(m*(n+m))
int intersection(int a[],int b[],int m,int n){
    int res=0;
    for(int i=0;i<m;i++){ // traverse arr a[]
        bool flag=false;
        for(int j=0;j<i;j++){ // check if a[i] is present in a[0 .... i-1]
            if(a[i]==a[j]){
                flag=true;
                break;
            }
        }
        if(flag) continue; // if present ignore it
        for(int j=0;j<n;j++){ // otherwise check in b[]
            if(a[i]==b[j]){   // if present update res
                res++;
                break;
            }
        }
    }
    return res;
}

// efficient solution
/* we can insert elements of both arrays in 2 different setss and traverse 1 of them and check its
   presence in 2 set and update res accordingly, but we can optimize it further as shown below*/
int intersect(int a[],int b[],int m,int n){
    int res=0;
    unordered_set<int> s(a,a+m); // insert all elements of a[] in set s
    for(int i=0;i<n;i++){ // traverse through b[]
        if(s.find(b[i])!=s.end()){ // if element is present in set s
            res++;                 // increment res
            s.erase(b[i]);         // remove b[i] from set s
        }                          // in order to avoid repetition cases
    }
    return res;
}

int main(){
    int a[]={10,15,20,5,30};
    int m=5;
    int b[]={30,5,30,80};
    int n=4;
    cout << intersection(a,b,m,n) << endl;
    cout << intersect(a,b,m,n) << endl;
    return 0;
}