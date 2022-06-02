#include<bits/stdc++.h>
using namespace std;
// to print array of vector type
void print(vector<int> arr[], int m){
    for(int i=0;i<m;i++){
        for(int j=0;j<arr[i].size();j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
// to print 2D vector
void print1(vector<vector<int>> &arr1){
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr1[i].size();j++){
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int m=3,n=2;
    // array of vector
    vector<int> arr[m];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i].push_back(i);
        }
    }
    print(arr,m);

    // 2D vector
    vector<vector<int>> arr1;
    for(int i=0;i<m;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            v.push_back(i);
        }
        arr1.push_back(v);
    }
    print1(arr1);
    return 0;
}