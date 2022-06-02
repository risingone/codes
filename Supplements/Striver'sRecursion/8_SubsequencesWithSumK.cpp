#include<bits/stdc++.h>
using namespace std;

// To print All the Subsequence with Sum k
void getSumKSubSeq(int ind,vector<int> &ds, int s,int sum,int arr[],int &n){
    if(ind==n){
        if(s==sum){
            for(auto &it: ds){
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[ind]);
    s += arr[ind];
    // pick
    getSumKSubSeq(ind+1,ds,s,sum,arr,n);
    s -= arr[ind];
    ds.pop_back();
    // not pick
    getSumKSubSeq(ind+1,ds,s,sum,arr,n);
}

// To print only One Subsequence with sum K
bool printS(int ind,vector<int> &ds,int s,int sum,int arr[],int &n){
    if(ind==n){
        // condition satisfied
        if(s==sum){
            for(auto &it: ds) cout << it << " ";
            cout << endl;
            return true;
        }
        // condition not satisfied
        else return false;
    }
    // pick
    ds.push_back(arr[ind]);
    s += arr[ind];
    if(printS(ind+1,ds,s,sum,arr,n)==true){
        return true;
    }

    s -= arr[ind];
    ds.pop_back();
    // not pick
    if(printS(ind+1,ds,s,sum,arr,n)==true){
        return true;
    }
    return false;
}

// To count number of subsequences with sum = k
int countS(int ind,int s,int sum,int arr[],int &n){
    // condition not satisfied
    // strictly done if array contains positives only
    if(s>sum) return 0;
    if(ind==n){
        // condition satisfied
        if(s==sum) return 1;
        // condition not satisfied
        else return 0;
    }
    // pick
    s += arr[ind];
    int l = countS(ind+1,s,sum,arr,n);

    s -= arr[ind];
    // not pick
    int r = countS(ind+1,s,sum,arr,n);

    return l+r;
}

int main(){
    int arr[] = {1,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=2;
    vector<int> ds;
    getSumKSubSeq(0,ds,0,sum,arr,n);
    cout << "To print only one subsequence!" << endl;
    printS(0,ds,0,sum,arr,n);
    cout << "To count number of Subsequences!" << endl;
    cout << countS(0,0,sum,arr,n) << endl;
    return 0;
}