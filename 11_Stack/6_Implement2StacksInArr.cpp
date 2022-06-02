#include<bits/stdc++.h>
using namespace std;

struct TwoStacks{
    int *arr,cap,top1,top2;
    // creates 2Stack of size c
    TwoStacks(int n){
        cap = n;
        top1 = -1;
        top2 = cap;
        arr = new int[n];
    }
    void push1(int x){
        if(top1<(top2-1)){
            top1++;
            arr[top1]=x;
        }
        else{
            cout << "Stack OverFlow!" << endl;
        }
    }
    void push2(int x){
        if(top1<(top2-1)){
            top2--;
            arr[top2]=x;
        }
        else{
            cout << "Stack OverFlow!" << endl;
        }
    }
    int pop1(){
        if(top1>=0){
            int x = arr[top1];
            top1--;
            return x;
        }
        else{
            cout << "Stack UnderFlow!" << endl;
            exit(1);
        }
    }
    int pop2(){
        if(top2<cap){
            int x = arr[top2];
            top2++;
            return x;
        }
        else{
            cout << "Stack UnderFlow!" << endl;
            exit(1);
        }
    }
};

int main(){
    TwoStacks ts(5);
    // cout << ts.pop1() << endl;
    ts.push1(5);
    ts.push1(10);
    ts.push1(15);
    ts.push2(5);
    ts.push2(10);
    ts.push2(15); // overflow
    cout << ts.pop1() << endl;
    cout << ts.pop2() << endl;
    return 0;
}