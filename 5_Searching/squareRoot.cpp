#include<bits/stdc++.h>
using namespace std;
//M-1
int sqRootFloor(int x){ //naive
    int i=1;
    while(i*i <= x){
        i++;
    }
    return (i-1);
}
//M-2
int sqRootFloor2(int x){
    int low=1,high=x,ans=-1;
    while(low<=high){
        int mid = (low+high)/2;
        int mSq = mid*mid;
        if(mSq==x) return mid;
        else if(mSq>x) high=mid-1;
        else{             //if mid's square is < x
            low = mid+1;  // update ans with mid 
            ans=mid;      //in case exact sqroot don't exist it will give floor sqroot
        }
    }
    return ans;
}
int main() {
    int x=55;
    cout << sqRootFloor(x) << endl;
    cout << sqRootFloor2(x) << endl;
    return 0;
}