#include<bits/stdc++.h>
using namespace std;

// naive approach O((n-k)*k*k)
void printDistWind(int arr[],int n,int k){
    for(int i=0;i<=n-k;i++){
        int count=0;
        for(int j=0;j<k;j++){ // for every window of size k
            bool flag=false;
            for(int p=0;p<j;p++){ // from 0-curr. window ele.
                if(arr[i+j]==arr[i+p]){ // if curr. wind ele. already occ. in same window
                    flag=true;          // skip it
                    break;
                }
            }
            if(flag==false) count++; // else increase count of dist ele.
        }
        cout << count << " "; //print dist ele. count for every window
    }
}

// efficient approach O(n)
void printDistinct(int arr[],int n,int k){
    unordered_map<int,int> ump;
    for(int i=0;i<k;i++){ // freq. map of first k items
        ump[arr[i]]++;
    }
    cout << ump.size() << " "; // print its size
    // now we will use sliding window technique
    for(int i=k;i<n;i++){
        ump[arr[i-k]]--; // decrease 0th element freq of window
        if(ump[arr[i-k]]==0) ump.erase(arr[i-k]); // ifits freq become 0 remove it
        ump[arr[i]]++;  //if already present(i th ele) then inc. freq else add it
        cout << ump.size() << " ";
    }
}

int main(){
    int arr[] = {10,20,20,10,30,40,10};
    int n=7,k=4; // we have to find dist ele. in each window of size k
    printDistWind(arr,n,k);
    cout << endl;
    printDistinct(arr,n,k);
    return 0;
}