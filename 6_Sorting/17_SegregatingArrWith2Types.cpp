/*We can Segregate:
1) Positive and Negative
{15,-3,-2,18} -> {-3,-2,15,18}
2)Even and Odd
{15,14,13,12} -> {14,12,15,13}
3)Sort Binary Arr
{0,1,1,1,0} -> {0,0,1,1,1}*/
#include<bits/stdc++.h>
using namespace std;

void segregatePosNeg(int arr[],int n){ //naive approach O(3n) and O(n) space
    int temp[n],i=0;
    for(int j=0;j<n;j++){ // first store all - no.'s in temp
        if(arr[j]<0){
            temp[i] = arr[j];
            i++;
        }
    }
    for(int j=0;j<n;j++){  // store all + no.'s in temp
        if(arr[j]>=0){
            temp[i] = arr[j];
            i++;
        }
    }
    for(int j=0;j<n;j++)  // copy no's back to arr from temp
        arr[j] = temp[j];
}
// separate +ve and -ve numbers
void segPosNeg(int arr[], int n){  // we use Hoore's partition 
    int i=-1,j=n;
    while (true)
    {
        do{ i++; } while(arr[i]<0);
        do{ j--; } while(arr[j]>=0);
        if(i>=j) return;
        swap(arr[i],arr[j]);
    }
}
// separate even and odd numbers
void segEvenOdd(int arr1[],int n){
    int i=-1,j=n;
    while(true){
        do{ i++; } while((arr1[i]&1)==0);
        do{ j--; } while((arr1[j]&1)==1);
        if(i>=j) return;
        swap(arr1[i],arr1[j]);
    }
}
// separate 0 and 1 
void segBits(int arr[],int n){
    int i=-1,j=n;
    while(true){
        do{ i++; } while(arr[i]==0);
        do{ j--; } while(arr[j]==1);
        if(i>=j) return;
        swap(arr[i],arr[j]);
    }
}
int main(){
    int arr[] = {15,-3,-2,18};
    int arr1[] = {15,14,13,12};
    int arr2[] = {0,1,1,1,0};
    segregatePosNeg(arr, 4);
    segPosNeg(arr, 4);
    for(int i=0;i<4;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    segEvenOdd(arr1,4);
    for(int i=0;i<4;i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    segBits(arr2,5);
    for(int i=0;i<5;i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}