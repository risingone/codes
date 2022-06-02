#include<bits/stdc++.h>
using namespace std;
int check(int match,int arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        if((match&arr[i])==match) count++;
    }
    return count;
}
int maxAND (int arr[], int N)
{
    // Your code here
    int res=0;
    for(int bit=16;bit>=0;bit--){ // as size is given 10^5 so result can have 16 bits
        int count = check(res|(1<<bit),arr,N); // we start matching from MSB
        if(count>=2){                          // is count >=2 we set it
            res|=(1<<bit);
        }
    }
    return res;
}

int main(){
    int arr[] = {4,16,8,12};
    int n=4;
    cout << maxAND(arr,n) << endl;
    return 0;
}