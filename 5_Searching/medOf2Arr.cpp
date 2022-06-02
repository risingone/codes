/*Find median of two sorted arrays*/
#include<bits/stdc++.h>
using namespace std;
// M-1 naive approach O(n1 + n2)*log(n1 + n2)
float findMed(int a1[],int a2[],int n1,int n2){
     int tot=n1+n2;
    int temp[tot];
    float ans;
    for(int i=0;i<n1;i++){
        temp[i]=a1[i];        // store both arrays in a temp array
    }
    for(int i=0;i<n2;i++){
        temp[n1+i]=a2[i];
    }
    sort(temp, temp+tot);         // sort the array
    if(tot%2 != 0){               // if total no. of elem. is odd
        ans = (float)temp[tot/2]; // return middle element
    }                             // else return average of middle 2 elem.
    else{                     
        ans = (float)(temp[tot/2] + temp[tot/2 - 1])/2;
    }
    return ans;
}
// M-2 efficient approach O(log n1) where n1<=n2
double getMed(int a1[],int a2[],int n1,int n2){
    int begin1=0,end1=n1;
    while(begin1 <= end1){
        int i1=(begin1 + end1)/2;
        int i2=(n1 + n2 + 1)/2 - i1;
        int min1 = (i1==n1)?INT_MAX:a1[i1]; //since when i1 become n1 there will be no elem. in 2 grp so min1=infinite 
        int max1 = (i1==0)?INT_MIN:a1[i1-1];
        int min2 = (i2==n2)?INT_MAX:a2[i2];
        int max2 = (i2==0)?INT_MIN:a2[i2-1];
        if(max1 <= min2 && max2 <= min1){     // termination condition when 1st grp has all elem. < 2nd grp
            if((n1+n2)%2 == 0){
                return ((double)max(max1,max2)+min(min1,min2))/2;
            }
            else{
                return (double) max(max1,max2);
            }
        }
        else if(max1>min2) end1 = i1-1;
        else begin1 = i1+1;
    }
    return -1;
}
int main(){
    int a1[]={10,20,30,40,50};
    int a2[]={5,15,25,35,45};
    int n1=sizeof(a1)/sizeof(a1[0]);
    int n2=sizeof(a2)/sizeof(a2[0]);
    cout << findMed(a1,a2,n1,n2) << endl;
    cout << getMed(a1,a2,n1,n2) << endl;
    return 0;
}