#include<bits/stdc++.h>
using namespace std;
const int R=3;
const int C=4;

// largest Histogram function
int largestHist(int arr[],int n){
    int res=0,tn,curr;
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()]>=arr[i]){
            tn=s.top();
            s.pop();
            curr = arr[tn]*(s.empty()?i:(i-s.top()-1));
            res = max(res,curr);
        }
        s.push(i); 
    }
    while(!s.empty()){
        tn = s.top();
        s.pop();
        curr = arr[tn]*(s.empty()?n:(n-s.top()-1));
        res = max(res,curr);
    }
    return res;
}

int maxRectangle(int mat[R][C]){
    int res = largestHist(mat[0],C);
    for(int i=1;i<R;i++){
        for(int j=0;j<C;j++){
            if(mat[i][j]==1) mat[i][j] += mat[i-1][j]; // update row ele. by adding consq. 1s in its col.
        }
        // we cal. largest Histogram for each updated row
        res = max(res,largestHist(mat[i],C));
    }
    return res;
}

int main(){
    int mat[R][C]={{0,1,1,0},
                   {1,1,1,1},
                   {1,1,1,0}};
    cout << maxRectangle(mat) << endl;
    return 0;
}