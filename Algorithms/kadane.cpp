/*To find Largest Sum Contiguous Subarray
 in O(n) Time Complexity*/
#include<iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter size of Array: ";
    cin>>size;
    // int A[]={-5,4,6,-5,4,-1};
    int A[size];
    cout << "Enter elements of Array: ";
    for(int i=0;i<size;i++){
        cin >> A[i];
    }
    int max=A[0];
    int curr=0;
    int n= sizeof(A)/sizeof(A[0]);
    for(int i=0;i<n;i++){       // We will traverse the array
        curr=curr+A[i];         // if current sum is greater than
        if(curr>max){           // max sum we will update max
            max=curr;           // if current sum is less than 0
        }                       // we will update it to 0
        if(curr<0){
            curr=0;
        }
    }
    cout << max;
    return 0;
}
