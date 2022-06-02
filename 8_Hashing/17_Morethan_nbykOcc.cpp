#include<bits/stdc++.h>
using namespace std;

// M-1 Naive Solution O(n logn), answer will be in sorted fashion
void printNByK(int arr[],int n,int k){
    sort(arr,arr+n);  // sort the array
    int i=1,count=1;
    while(i<n){       // traverse arr
        while(i<n && arr[i]==arr[i-1]){ // if arr[i]==arr[i-1] update count
            i++;
            count++;
        }
        if(count>(n/k)){                // if count>(n/k) print arr[i-1]
            cout << arr[i-1] << " ";    // as i is point to ele. ahead
        }
        count = 1;  // update count
        i++;        // and i then check for next ele.
    }
}

// M-2 efficient Solution O(n), answer will be in random order
void printNByK1(int arr[],int n,int k){
    unordered_map<int,int> ump;
    for(int i=0;i<n;i++){ // store freq of all ele.
        ump[arr[i]]++;
    }
    for(auto &it: ump){   // print ele. with freq > (n/k)
        if(it.second>(n/k)){
            cout << it.first << " ";
        }
    }
}

//M-3 => res_count <= k-1 as for k-> k*(n/k + 1) <=n =) n+k<=n not possible
void majEle(int arr[],int n,int k){
    unordered_map<int,int> ump;
    for(int i=0;i<n;i++){
        if(ump.find(arr[i])!=ump.end()){
            ump[arr[i]]++;
        }
        else if(ump.size()<k){
            ump.insert({arr[i],1});
        }
        else{
            for(auto &it: ump){
                it.second--;
                if(it.second==0) ump.erase(it.first);
            }
        }
    } // at end ump will contain potential solutions;
    for(auto &it: ump){
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==it.first) count++;
        }
        if(count>(n/k)){
            cout << it.first << " ";
        }
    }
}

int main(){
    int arr[]={30,10,20,20,10,20,30,30};
    int n=8,k=4;
    printNByK(arr,n,k);
    cout << endl;
    printNByK1(arr,n,k);
    cout << endl;
    majEle(arr,n,k);
    return 0;
}