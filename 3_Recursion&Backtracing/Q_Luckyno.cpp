/*Lucky numbers are subset of integers. Rather than going into much theory, let us see the process of arriving at lucky numbers,
Take the set of integers
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,……
First, delete every second number, we get following reduced set.
1, 3, 5, 7, 9, 11, 13, 15, 17, 19,…………
Now, delete every third number, we get
1, 3, 7, 9, 13, 15, 19,….….
Continue this process indefinitely……*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int count=2;
    bool isLucky(int n) {
        // code here
        if(n<count) return true;
        else if(n%count == 0) return false;
        n=n-(n/count);
        count++;
        return isLucky(n);
    }
};
int main(){
    Solution s;
    int n;
    cout << "Enter number: ";
    cin >> n;
    if(s.isLucky(n)){
        cout << "It is a lucky number" << endl;
    }
    else{
        cout << "It is not a lucky number" << endl;
    }
    return 0;
}