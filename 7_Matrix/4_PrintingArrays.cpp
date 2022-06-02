#include<bits/stdc++.h>
using namespace std;
// M-2
const int R=3;
const int C=2;
void print1(int mat1[R][C]){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }
}

// M-1
void print(int mat[][2],int m){ // it can print any row size 2d arr with 2columns
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int mat[3][2] ={{10,20}, {30,40}, {50,60}};
    print(mat,3);
    int mat1[R][C] = {{15,25}, {35,45}, {55,65}};
    print1(mat1);
    return 0;
}