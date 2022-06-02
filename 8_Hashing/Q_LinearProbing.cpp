#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
 vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
        //Your code here
        vector<int> vec(hashSize,-1);
        for(int i=0;i<sizeOfArray;i++){
            int ind=arr[i]%hashSize;
            if(vec[ind]==-1){     // if index is empty
                vec[ind]=arr[i];
            }
            else{
                int count=0;
                while(vec[ind]!=-1 && count<=hashSize){ // traverse till we find an empty solt or return back
                    if(vec[ind]==arr[i]) break; // if ele. is already present skip
                    ind=(ind+1)%hashSize;
                    count++;
                }
                if(vec[ind]==-1){
                    vec[ind]=arr[i];
                }
            }
        }
        return vec;
    }
};

int main(){
    Solution s;
    int arr[] = {4,14,24,4};
    vector<int> res = s.linearProbing(10,arr,4);
    for(auto &it: res){
        cout << it << " ";
    }
    return 0;
}