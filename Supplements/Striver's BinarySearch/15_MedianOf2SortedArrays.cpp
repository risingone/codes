// LC 4
#include<bits/stdc++.h>
using namespace std;

/* Naive Using Merge 2 sorted array Store these in 1 sorted arr
   then calculate median TC: O(n1+n2) SC: O(n1+n2)
   We can optimize it further by using counter insted of using space
   which will make its SC: O(1)*/

// Efficient Method O(log(min(n1,n2)))
double findMedian(int arr1[],int &n1,int arr2[],int &n2){
    // As TC: O(logn1), so to minize it
    if(n1>n2) findMedian(arr2,n2,arr1,n1);
    int low=0,high=n1;
    while(low<=high){
        int cut1=(low+high)>>1;
        int cut2=(n1+n2+1)/2 - cut1;

        int left1 = (cut1==0)?INT_MIN:arr1[cut1-1];
        int left2 = (cut2==0)?INT_MIN:arr2[cut2-1];

        int right1 = (cut1==n1)?INT_MAX:arr1[cut1];
        int right2 = (cut2==n2)?INT_MAX:arr2[cut2];

        if(left1<=right2 && left2<=right1){
            // for even elements
            if((n1+n2)%2 == 0){
                return (max(left1,left2) + min(right1,right2))/2.0;
            } else{
                return max(left1,left2);
            }
        } else if(left1>right2){
            high=cut1-1;
        } else {
            low=cut1+1;
        }
    }
    return 0.0;
}

int main(){
    int arr1[] = {7,12,14,15,16};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {1,2,3,4,9,11};
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    cout << findMedian(arr1,n1,arr2,n2) << endl;
    return 0;
}