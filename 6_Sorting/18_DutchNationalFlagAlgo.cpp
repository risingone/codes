/* below is shown for 0's,1's and 2's
{0,1,0,2,1,2}->{0,0,1,1,2,2}
2)we could also do around 2 eg:
{2,1,2,20,10,20,1}->{1,1,2,2,20,10,20}
3)we can partition around a range too eg={5-10}
{10,5,6,3,20,9,40}->{3,5,6,9,10,20,40}
*/
#include<bits/stdc++.h>
using namespace std;

void sort(int arr[],int n){  
    int lo=0,hi=n-1,mid=0;
    while(mid<=hi){
        if(arr[mid]==0){  // when element is 0 move lo and mid
            swap(arr[lo],arr[mid]);
            lo++;
            mid++;
        }
        else if(arr[mid]==1){// when 1 move mid
            mid++;
        }
        else{
            swap(arr[mid],arr[hi]);// otherwise swap and update hi
            hi--;
        }
    }
}
int main(){
    int arr[] = {0,1,2,1,1,2};
    sort(arr,6);
    for(int i=0;i<6;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}