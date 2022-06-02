#include<bits/stdc++.h>
using namespace std;

class Solution
{   
    public:
    //Function to generate SubVec 
    void subMatrix(int n,vector<vector<int>>& matrix,int I,int J,vector<vector<int>>& subVec){
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(i!=I){ // we skip the i th row
                b=0;
                for(int j=0;j<n;j++){
                    if(j!=J){ // we skip the jth column
                        subVec[a][b]=matrix[i][j];
                        b++;
                    }
                }
                a++;
            }
        }
    }
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int>>& matrix, int n)
    {
        // code here 
        int det=0;
        if(n==1){
            return matrix[0][0];
        }
        if(n==2){
            det = (matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]);
        }
        else{
             vector<vector<int>> subVec(n-1,vector<int>(n-1)); // we declare subVec here
             for(int i=0;i<n;i++){
                 subMatrix(n,matrix,0,i,subVec); // it fills subVec for every particular row
                 det += matrix[0][i] * ((i&1)?-1:1)*determinantOfMatrix(subVec,n-1); // i&1 tell about -1 or +1
             }
        }
        return det;
    }
};
int main(){
    Solution s;
    vector<vector<int>> matrix = {{1, 0, 2, -1}, // 30
                                  {3, 0, 0, 5},
                                  {2, 1, 4, -3},
                                  {1, 0, 5, 0}};
    cout << s.determinantOfMatrix(matrix,matrix.size());
    return 0;
}