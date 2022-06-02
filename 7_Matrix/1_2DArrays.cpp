#include<bits/stdc++.h>
using namespace std;

int main(){
    // all in one step
    int arr[3][2] = {{10,20},{30,40},{50,60}};
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
    // predefined size
    int m=3,n=2;
    int arr1[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr1[i][j]=i+j;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}