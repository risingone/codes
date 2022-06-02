#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m=3,n=2;
    // 2D array
    vector<int> arr[m]; // array of size m and type vector<int>
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i].push_back(j);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // 2D vector
    vector<vector<int>> arr1;
    for(int i=0;i<m;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            v.push_back(10);
        }
        arr1.push_back(v);
    }
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr1[i].size();j++){
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}