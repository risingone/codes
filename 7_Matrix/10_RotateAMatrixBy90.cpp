#include<bits/stdc++.h>
using namespace std;
const int R=3;
const int C=3;

// naive
void rotate90(int mat[R][C]){
    int temp[R][C];
    for(int i=0;i<R;i++){ // copy elements to temp in required fashion
        for(int j=0;j<C;j++){
            temp[R-j-1][i] = mat[i][j];
        }
    }
    for(int i=0;i<R;i++){ // place elements back
        for(int j=0;j<C;j++){
            mat[i][j]=temp[i][j];
        }
    }
}

// efficient solution
void Effrotate90(int mat[R][C]){
    for(int i=0;i<R;i++){                    // find the transpose
        for(int j=i+1;j<C;j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    for(int i=0;i<C;i++){                     // revers all columns
        int low=0,high=R-1;
        while(low<high){
            swap(mat[low][i],mat[high][i]);
            low++;
            high--;
        }
    }
}

int main(){
    int mat[R][C] = {{1,2,3},
                     {4,5,6},
                     {7,8,9}};
    // rotate90(mat);
    Effrotate90(mat);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}