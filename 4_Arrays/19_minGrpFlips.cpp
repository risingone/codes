/*To find the minimum group flips to make all array elements same
e.g:i/p-> arr[] = {1,1,0,0,0,1} =)o/p-> From 2 to 4*/
#include<bits/stdc++.h>
using namespace std;
void printGroups(bool arr[],int n){ // from examples we can see there will be 2 possiblities: 
    for(int i=1;i<n;i++){           // 1) 11000111001, 00110001100 in which a group's occurence is < others
        if(arr[i]!=arr[i-1])        // 2) 00111000011, 11000011110 in it they have equal occurences
        {                           // we check if ith element is not equal to i-1th element
            if(arr[i]!=arr[0]){         // we check if ith element is not equal to 0th element & then print
            cout << "From " << i << " to ";
            }
            else{                          // to print end of group
            cout << i-1 << endl;
            }
        }
    }
    if(arr[n-1] != arr[0]){   //to print end of group if no. occurs at last index
        cout << n-1 << endl;
    }
}
int main(){
    bool A[] = {1,0,0,0,1,0,0,1,1,1,1};
    printGroups(A,11);
    return 0;
}