#include<bits/stdc++.h>
using namespace std;

struct MyDS{
    deque<int> dq;
    // insert min < prev min
    void insertMin(int x){
        dq.push_front(x);
    }
    // insert max > prev max
    void insertMax(int x){
        dq.push_back(x);
    }
    int getMin(){
        return dq.front();
    }
    int getMax(){
        return dq.back();
    }
    int extractMin(){
        int res = dq.front();
        dq.pop_front();
        return res;
    }
    int extractMax(){
        int res = dq.back();
        dq.pop_back();
        return res;
    }
};

int main(){
    MyDS d;
    d.insertMin(10);
    d.insertMax(15);
    d.insertMin(5); // 5 10 15
    cout << d.extractMin() << endl;
    cout << d.extractMax() << endl;
    cout << d.getMax() << endl;
    cout << d.getMin() << endl;
    return 0;
}