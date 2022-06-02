#include<bits/stdc++.h>
using namespace std;
const int R=3;
const int C=3;
// assumption-> odd size matrix and all distinct elements
int matMed(int mat[R][C]){
    int min=mat[0][0], max=mat[0][C-1]; // declare and find minm amd maxm elements
    for(int i=1;i<R;i++){               // present in an array
        if(mat[i][0]<min){ min = mat[i][0]; }
        if(mat[i][C-1]>max){ max = mat[i][C-1]; }
    }
    int medPos = (R*C + 1)/2; // medPos will be in middle of total elements
    while(min<max){ // modified binaysearch
        int mid = (min+max)/2;
        int midPos=0;
        for(int i=0;i<R;i++){ // find no. of elements <= mid present in all rows
            midPos += upper_bound(mat[i],mat[i]+C,mid) - mat[i]; // and store in mid pos
        }
        if(midPos<medPos) min = mid+1; // modify  max and min accordingly
        else{
            max=mid;
        }
    }
    return min;
}


int main(){
    int mat[R][C] = {{1,10,20},
                     {15,25,30},
                     {5,8,40}};
    cout << matMed(mat) << endl;
     vector<int> vec;
     for(int i=0;i<R;i++){
         for(int j=0;j<C;j++){
             vec.push_back(mat[i][j]); // add all elements to a 1D vector
         }
     }
    sort(vec.begin(),vec.end());  // sort the vector
    cout << vec.size() << endl;
    cout << vec[vec.size()/2];    // return middle element
    return 0;
}