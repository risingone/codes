/*To find if the given array has an equilibrium point or not
e.g i/p-> arr[] = {3,4,8,-9,20,6} // 20 is eq. pt as sum on its left(6) is = sum on its right(6)
    o/p-> yes
    i/p-> arr[] = {4,2,-2} // 4 is eq. pt
    o/p-> yes*/
#include<bits/stdc++.h>
using namespace std;
// M-1 naive approach O(n^2)
bool equiPoint(int arr[],int n){
    for(int i=0;i<n;i++){       // for each element 
        int l_sum=0,r_sum=0;    
        for(int j=0;j<i;j++){   // to calculate l_sum
            l_sum += arr[j];
        }
        for(int j=i+1;j<n;j++){  // to calculate r_sum
            r_sum += arr[j];
        }
        if(l_sum==r_sum) return true;
    }
    return false;
}
// M-2 using prefix sum O(n)
bool isEqPoint(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){     // store sum of whole array in sum
        sum += arr[i];
    }
    int l_sum=0;
    for(int i=0;i<n;i++){                     // while traversing through the array
        if(l_sum == sum-arr[i]) return true;  
        l_sum += arr[i];                      // keep on updating l_sum
        sum -= arr[i];                        // & sum
    }
    return false;
}
int main(){
    int A[]={3,4,8,-9,20,6};
    if(equiPoint(A,6)){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    cout << isEqPoint(A,6) << endl;
    return 0;
}