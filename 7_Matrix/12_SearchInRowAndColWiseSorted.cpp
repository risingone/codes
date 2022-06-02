#include<bits/stdc++.h>
using namespace std;
const int R=4;
const int C=4;
// naive O(R*C)
void search(int mat[R][C], int x){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(mat[i][j] == x){
                cout << "Found at (" << i <<", " << j << ")";
                return;
            }
        }
    }
    cout << "Not Found" << endl;
}

//Efficient Search O(R+C)
void Effsearch(int mat[R][C],int x){
    int i=0,j=C-1; // we will start from top right-most element
    while(i<R && j>=0){// and traverse till we don't reach Rth row or -1th column
        if(mat[i][j]==x){ // if we get element we return its indices
            cout << "Found at (" << i <<", " << j << ")";
            return;
        }
        else if(mat[i][j]>x) j--; // if target element is < curr element move to column on left
        else{
            i++; // other wise move to next row
        }
    }
    cout << "Not Found" << endl;
}

int main(){
    int mat[R][C] = {{10,20,30,40},
                     {15,25,35,45},
                     {27,29,37,48},
                     {32,33,39,50}};
    int x=29;
    search(mat,x);
    return 0;
}