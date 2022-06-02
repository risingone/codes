#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Point{   // user defined data type
    int x,y;
};
bool myCmp(Point p1, Point p2){  // comparison functon
    return (p1.y > p2.y); // for descending (p1.x>p2.x)
}

int main(){
    // for arrays
    int arr[] = {10,20,5,7};
    sort(arr,arr+4);
    for(int x: arr){
        cout << x << " ";
    }
    cout << endl;
    sort(arr,arr+4,greater<int>());
    for(int x: arr){
        cout << x << " ";
    }
    cout << endl;
    cout << endl;
    // for vectors
    vector<int> v = {5,7,20,10};
    sort(v.begin(),v.end());
    for(int x: v)
        cout << x << " ";
    cout << endl;
    sort(v.begin(),v.end(),greater<int>());
    for(int x: arr)
        cout << x << " ";
    cout << endl;
    cout << endl;
    // for user defined data type
    Point arr1[] = {{3,10},{2,8},{5,4}};
    sort(arr1,arr1+3, myCmp);
    for(auto it : arr1){
        cout << "(" << it.x << "," << it.y << ") ";
    }
    cout << endl;
    return 0;
}