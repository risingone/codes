#include<bits/stdc++.h>
using namespace std;
const int R=4;
const int C=4;

void bTraversal(int mat[R][C]){
    if(R==1){ // edge case when there is only one row
        for(int i=0;i<C;i++){
            cout << mat[0][i] << " ";
        }
    }
    else if(C==1){  // edge case  when there is only 1 column
        for(int i=0;i<R;i++){
            cout << mat[i][0] << " ";
        }
    }
    else{
        for(int i=0;i<C;i++){ // to print 1 row
            cout << mat[0][i] << " ";
        }
        for(int i=1;i<R;i++){ // to print last colums
            cout << mat[i][C-1] << " ";
        }
        for(int i=C-2;i>=0;i--){ // print last row
            cout << mat[R-1][i] <<" ";
        }
        for(int i=R-2;i>=1;i--){ // print first column
            cout << mat[i][0] << " ";
        }
    }
}

int main(){
    int mat[R][C] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    bTraversal(mat);
}