#include<bits/stdc++.h>
using namespace std;

// M-1: Naive Approach
int celebrity(vector<vector<int>>& M,int n){
    for(int i=0;i<n;i++){
        bool celeb=true;
        for(int j=0;j<n;j++){
            // check celeb don't know anyone
            if(M[i][j]==1){
                celeb=false;
                break;
            }
            // check if someone don't knows i
            if((j!=i) && M[j][i]==0){
                celeb=false;
                break;
            }
        }
        if(celeb) return i;
    }
    return -1;
}

// M-2 Efficient Approach
int celebrity2(vector<vector<int>>& M,int n){
    int a=0,b=n-1;
    while(a<b){
        // if M[a][b]=1 =) so b can be celeb. but a can't
        if(M[a][b]){
            a++;
        }
        else{ // else a can be, but b can't
            b--;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=a&&(M[a][i] || !M[i][a])) return -1;
    }
    return a;
}

int main(){
    int n=5;
    vector<vector<int>> M={{0, 1, 0, 1, 0},
                           {1, 0, 1, 1, 0},
                           {0, 0, 0, 1, 1},
                           {0, 0, 0, 0, 0},
                           {1, 0, 1, 1, 0}};
    cout << celebrity(M,n) << endl;
    cout << celebrity(M,n) << endl;
    return 0;
}