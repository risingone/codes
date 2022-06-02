#include<bits/stdc++.h>
using namespace std;
// array of size 10^7(int,double..) is allowed globally and size 10^8(bool)
int main() {
    //Arrays  -> int arr[100];
    // array of size 10^6(int,double..) is allowed in main and size 10^7(bool)
    array<int, 3> A; // -> {?,?,?}
    array<int, 5> arr = {1}; // -> {1, 0, 0, 0, 0} while if you do it globally all elements will be 1
    arr.at(1); // to get element at index 1
    arr.fill(10); // -> {10,10,10,10,10}
    for(int i=0;i<5;i++){
        cout << arr.at(i) << " ";
    }
    cout << endl;
    // iterators
    // begin(), end(), rbegin(), rend()
    array<int, 5> arr1 = {1, 3, 4, 5, 6};
    for(auto it= arr1.begin(); it!=arr1.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
    for(auto it=arr1.rbegin();it!=arr1.rend();it++){
        cout << *it << " ";
    }
    cout << endl;
    for(auto it=arr1.end()-1;it>=arr1.begin();it--){
        cout << *it << " ";
    }
    cout << endl;
    // for each loop
    for(auto it: arr1){
        cout << it << " ";
    }
    cout << endl;
    string s = "xhegcwe";
    // x h e g c w e
    for(auto c:s) {
        cout << c << " ";
    }
    cout << endl;
    // size
    cout << arr1.size() << endl;
    // front
    cout << arr1.front() << endl;
    // back
    cout << arr1.back() << endl;
    return 0;
}