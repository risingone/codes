#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_set<int> check;
    bool isHappy(int n) {
        int x=n;
        int sum=0;
        while(x){
            int d=x%10;
            sum += d*d;
            x/=10;
        }
        if(check.find(sum)!=check.end()) return false;
        else
            check.insert(sum);
        if(sum==1){
            check.clear();
            return true;
        }
        else{
            isHappy(sum);
            if(check.empty()) return true;
            else
                return false;
        }
    }
};
int main(){
    int n;
    cout << "Enter number: ";
    cin>>n;
    Solution obj;
    if(obj.isHappy(n)){
        cout << "It is a happy number" << endl;
    }
    else{
        cout << "It is not a happy number" << endl;
    }
    return 0;
}