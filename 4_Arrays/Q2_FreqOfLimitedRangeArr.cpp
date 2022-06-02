#include<bits/stdc++.h>
using namespace std;

// M-1 TC: O(2*n) SC: O(n)
void frequencyCount(vector<int>& arr,int N, int P){ 
    unordered_map<int,int> ump;
    for(int i=0;i<N;i++){
        ump[arr[i]]++;
    }
    for(int i=0;i<N;i++){
        if(ump.find(i+1)==ump.end()){
            arr[i]=0;
        } else{
            arr[i]=ump[i+1];
        }
    }
}

// M-2 TC: O(2*n) SC: O(1)
void frequencyCount2(vector<int>& arr,int N, int P){  // 2 3 2 4 5
    int i=0;                                          // 3 -1 2 4 5
    while(i<N){                                       // 2 -1 -1 4 5
        if(arr[i]<=0 || arr[i]>N){                    // 0 -2 -1 4 5
            if(arr[i]>N) arr[i]=0;                    // 0 -2 -1 -1 5
            i++;                                      // 0 -2 -1 -1 -1
            continue;
        }
        int e=arr[i]-1;
        if(arr[e]<=0){
            arr[e]--;
            arr[i]=0;
            i++;
        }
        else{
            arr[i] = arr[e];
            arr[e] = -1;
        }
    }
    for(int i=0;i<N;i++){                            // 0 2 1 1 1
            arr[i] *= -1;
        }
}

int main(){
    vector<int> arr={2, 3, 2, 4, 5};
    int N=5;
    int P=5;
    // frequencyCount(arr,N,P); // 0 2 1 1 1
    frequencyCount2(arr,N,P);
    for(auto &it: arr){
        cout << it << " "; // as arr stores freq*(-1)
    }
    return 0;
}