#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> res;
bool canAddQueen(int r,int c,vector<vector<int>>& queens){  //to check if a queen can be placed at a particular pos
    for(int i=0;i<queens.size();i++){
         int dx=abs(r-queens[i][0]);
         int dy=abs(c-queens[i][1]);
         if(dx==0 || dy==0 || dx==dy) return false;
    }
    return true;
}
void dfs(vector<vector<char>>& board,int r,vector<vector<int>>& queens){
        if(queens.size()==board.size()){// storing a possible solution in res vector
              vector<string> rows;
              for(int i=0;i<board.size();i++){
                  string s = "";
                  for(int j=0;j<board.size();j++){
                       s = s + board[i][j];
                  }
                  rows.push_back(s);
              }
          res.push_back(rows);
        }
        for(int c=0;c<board.size();c++){
            if(canAddQueen(r,c,queens)){
              board[r][c]='Q';
              vector<int> vec;
              vec.push_back(r);
              vec.push_back(c);
              queens.push_back(vec); //position of queen is placed
              dfs(board,r+1,queens);
              board[r][c]='.';// backtracing
              queens.pop_back();
             }
       }
    }
vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board;
        for(int i=0;i<n;i++){
            vector<char> v;
            for(int j=0;j<n;j++){
                v.push_back('.');
            }
            board.push_back(v);
        }
        vector<vector<int>> queens;  //in order to store position of queen to check safe position
        dfs(board,0,queens);// recursive function
        return res;
}
int main(){
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    vector<vector<string>> ans=solveNQueens(n);
    cout << ans.size() << endl;// print total number of such configurations
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << endl;
        }
        cout << " ----------------------" << endl;
    }
    return 0;
}