#include<bits/stdc++.h>
using namespace std;
const int R=4;
const int C=4;

void printSnake(int mat[R][C]){
    for(int i=0;i<R;i++){
        if((i&1)==0){
            for(int j=0;j<C;j++){ // for even rows traverse in forward direction
                cout << mat[i][j] << " ";
            }
        }
        else{
            for(int j=C-1;j>=0;j--){ // for odd rows traverse in backward fashion
                cout << mat[i][j] << " ";
            }
        }
    }
}

int main(){
    int mat[R][C]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    printSnake(mat);
}