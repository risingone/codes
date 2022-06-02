#include<bits/stdc++.h>
using namespace std;

namespace raj {
    int val =50;
    int getVal() {
        return val*10;
    }
}
// create a data type where we store (string, int, double, char)
struct node {
    string str;
    int num;
    double doub;
    char x;
    node(string str_,int num_,double doub_,char x_) {
        str = str_;
        num = num_;
        doub = doub_;
        x = x_;
    }
};
int main(){
    double val = 10.0;
    // std::cout << val << std::endl; //in case we don't use namespace std
    cout << val << endl; // prints 10.0
    cout << raj::val << endl; // prints 50
    cout << raj::getVal()  << endl; // prints 500
     
    // create a data type where we store (string, int, double, char)
    // // wrong way of defining
    // node raj;
    // raj.str = "striver";
    // raj.num = 79;
    // raj.doub = 91.0;

     // correct way of defining
    // node* raj = new node("striver",79,91.0,'a');
    node raj = node("striver",79,91.0,'a');

    return 0;
}
