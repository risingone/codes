#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<int> &A, vector<int> &B, int N) {
        //code here
        unordered_map<int,int> ump;
        for(int i=0;i<N;i++){ // store freq of ele. present in A
            ump[A[i]]++;
        }
        for(int i=0;i<N;i++){
            if(ump.find(B[i])!=ump.end()){
                ump[B[i]]--;               // dec. freq.
                if(ump[B[i]]==0){          // if freq. become 0
                    ump.erase(B[i]);       // remove ele.
                }
            }
            else{
                return false;  // if encounter a new dist. ele. in B
            }
        }
        return ump.size()==0;
    }
};

int main(){
    Solution s;
    int N=5;
    vector<int> A={1,2,5,4,0};
    vector<int> B={2,4,5,0,1};
    cout << s.check(A,B,N) << endl;
    return 0;
}