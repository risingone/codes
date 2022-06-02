#include<iostream>
#include<queue>
using namespace std;

int main(){
    cout << "priority queue(maxHeap based)" << endl;
    priority_queue<int> pq; // by default it implements maxHeap
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout << pq.size() << endl;
    cout << pq.top() << endl;
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    // priority queue implementing minHeap
    cout << "priority queue(maxHeap based)" << endl;
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(10);
    pq2.push(15);
    pq2.push(5);
    cout << pq2.size() << endl;
    cout << pq2.top() << endl;
    while(!pq2.empty()){
        cout << pq2.top() << " ";
        pq2.pop();
    }
    return 0;
}