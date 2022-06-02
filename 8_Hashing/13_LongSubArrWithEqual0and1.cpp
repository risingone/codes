#include<bits/stdc++.h>
using namespace std;

// naive Solution
int longestSub(int arr[],int n){
    int res=0;
    for(int i=0;i<n;i++){  // for each index
        int count0=0,count1=0;
        for(int j=i;j<n;j++){  // take count of 0 and 1 succeding ele.
            if(arr[j]==0) count0++;
            else
                count1++;
            if(count0 == count1) // if both count's are equal
                res = max(res,count0+count1); // update res acc.
        }
    }
    return res;
}

//efficient solution
int longestSub1(int arr[],int n){
    for(int i=0;i<n;i++){       // we convert 0's in array to -1's
        if(arr[i]==0) arr[i]=-1;
    }
    // now the Ques is to find Longest SubArr with Sum 0
    unordered_map<int,int> ump;
    int res=0,preSum=0;
    for(int i=0;i<n;i++){
        preSum += arr[i];
        if(preSum==0) res =i+1;
        if(ump.find(preSum)!=ump.end()){
            res = max(res,i-ump[preSum]);
        }
        else{
            ump.insert({preSum,i});
        }
    }
    return res;
}

int main(){
    int arr[]={0,0,1,1,1,1,1,0};
    int n=8;
    cout << longestSub(arr,n) << endl;
    cout << longestSub1(arr,n) << endl;
    return 0;
}