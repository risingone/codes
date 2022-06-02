#include<bits/stdc++.h>
using namespace std;
int main(){
    // M-1
    // int m=3,n=2;
    // int **arr;
    // arr = new int *[m]; // array of pointers created dynamically
    // for(int i=0;i<m;i++){
    //     arr[i]=new int[n];// each array element -> dynamically created array of size n
    // }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         arr[i][j] = 10;
    //         cout << arr[i][j] << " ";
    //     }
    // }

    //M-2
    int m=3,n=2;
    int *arr[m];
    for(int i=0;i<m;i++){
        arr[i] = new int[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = 10;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}