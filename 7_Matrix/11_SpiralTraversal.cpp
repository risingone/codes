#include<bits/stdc++.h>
using namespace std;
const int R=4;
const int C=4;

void printSpiral(int mat[R][C],int R,int C){
    int top=0,left=0,bottom=R-1,right=C-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){     // top row
            cout << mat[top][i] << " "; 
        }
        top++;
        for(int i=top;i<=bottom;i++){     // right column
            cout << mat[i][right] << " ";
        }
        right--;
        if(top<=bottom){                  // bottom row(reverse order)
            for(int i=right;i>=left;i--){
                cout << mat[bottom][i] << " ";
            }
            bottom--;
        }
        if(left<=right){                  // left column(reverse order)
            for(int i=bottom;i>=top;i--){
                cout << mat[i][left] << " ";
            }
            left++;
        }
    }
}

int main(){
    int mat[R][C]={{1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12},
                   {13,14,15,16}};
    printSpiral(mat,R,C);
    return 0;
}