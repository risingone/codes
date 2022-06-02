/*In it we try to place n Queen's on n*n board such that they are safe from each other*/
#include<iostream>
using namespace std;
const int n=4;
void print(int board[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int board[n][n],int row,int col){
    int i,j;
    for(i=0;i<row;i++){                        //check for the row on left side
        if(board[i][col]==1) return false;
    }
    // for(i=0;i<col;i++){                        //check for column on upper side
    //     if(board[row][i]==1) return false;
    // };
    for(i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]==1) return false;
    }
    for(i=row,j=col;i>=0&&j<n;i--,j++){
        if(board[i][j]==1) return false;
    }
    return true;
}
bool nQueen(int board[n][n],int row){
    if(row == n){
        print(board);
        return true;
    } 
    for(int col=0;col<n;col++){
        if(isSafe(board,row,col)){
            board[row][col]=1;
            if(nQueen(board,row+1)) return true;
            board[row][col]=0;
        }
    }
    return false;
}

int main(){
    int board[n][n] ={0};
    if(!nQueen(board,0)){
        cout << "No possible way!";
    }
    return 0;
}