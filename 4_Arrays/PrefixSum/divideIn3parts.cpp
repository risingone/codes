/* Check if a given array can be divided into 3 parts with equal sum */
#include<bits/stdc++.h>
using namespace std;
// M-1
bool divEqual(int arr[],int n){
    int prefix_sum[n];
    int sum=0;
    for(int i=0;i<n;i++){  //O(n)
        sum += arr[i];
        prefix_sum[i] = sum;
    }
    // for(int i=0;i<n;i++){
    //     cout << prefix_sum[i] << " ";
    // }
    int l_sum=0,r_sum=prefix_sum[n-1];
    if(r_sum==0){
        return true;
    }
    for(int i=0;i<n;i++){
        l_sum = prefix_sum[i];
        r_sum = prefix_sum[n-1] - prefix_sum[i];
        if((2*(l_sum))==r_sum){
            int l2_sum=0,r2_sum=prefix_sum[n-1] - prefix_sum[i];
            for(int j=i+1;j<n;j++){
                l2_sum = prefix_sum[j] - prefix_sum[i];
                r2_sum = prefix_sum[n-1] - prefix_sum[j];
                if(l2_sum==r2_sum) return true;
            }
        }
    }
    return false;
}
//M-2
bool divEqual2(int arr[],int n){
    int i;
    // variable to store prefix sum
    int preSum = 0;
 
    // variables to store indices which
    // have prefix sum divisible by S/3.
    int ind1 = -1, ind2 = -1;
 
    // variable to store sum of
    // entire array.
    int S;
 
    // Find entire sum of the array.
    S = arr[0];
    for (i = 1; i < n; i++)
        S += arr[i];
 
    // Check if array can be split in
    // three equal sum sets or not.
    if(S % 3 != 0)
        return false;
     
    // Variables to store sum S/3
    // and 2*(S/3).
    int S1 = S / 3;
    int S2 = 2 * S1;
 
    for (i = 0; i < n; i++)
    {
        preSum += arr[i];
         
        // If prefix sum is equal to S/3
        // store current index.
        if (preSum == S1 && ind1 == -1)
            ind1 = i;
         
        // If prefix sum is equal to 2* (S/3)
        // store current index.
        else if(preSum  == S2 && ind1 != -1)
        {
            ind2 = i;
             
            // Come out of the loop as both the
            // required indices are found.
            break;
        }
    }
 
    // If both the indices are found
    // then print them.
    if (ind1 != -1 && ind2 != -1)
    {
        // cout << "(" << ind1 << ", "
        //                         << ind2 << ")";
        return true;
    }
 
    // If indices are not found return 0.
    return false;
}
//M-3
bool divEqual3(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    if(sum==0) return true;
    if(sum%3 != 0) return false;
    int l_sum=arr[0],r_sum=arr[n-1],i=1,j=n-2,s=sum;
    s = s -(l_sum+r_sum);
    while(i<j){
        if(l_sum<r_sum){
            l_sum += arr[i];
            s -= arr[i];
            i++;
        }
        if(r_sum<l_sum){
            r_sum += arr[j];
            s -= arr[j];
            j--;
        }
        if(l_sum==r_sum){
            if(s==(sum/3)){
                return true;
            }
            else {
                l_sum += arr[i];
                s -= arr[i];
                i++;
            }
        }
    }
    return false;
}
int main(){
    int A[]={1,2,3,2,2,2,5,1};
    int n=sizeof(A)/sizeof(A[0]);
    cout << divEqual(A,n) << endl;
    cout << divEqual2(A,n) << endl;
    cout << divEqual3(A,n) << endl;
    return 0;
}