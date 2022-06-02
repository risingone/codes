#include<bits/stdc++.h>
using namespace std;

int main(){
    // doesn't run on vs code but works on online compiler
    // priority_queue for pairs
    cout << "priority_queue for pairs" << endl;
    priority_queue<pair<int,int> > pr_pq;
    pr_pq.push({1,5});
    pr_pq.push({1,6});
    pr_pq.push({1,7});
    cout << pr_pq.size() << endl;
    cout << pr_pq.top().first << " " << pr_pq.top().second << endl;
    pr_pq.pop();
    cout << pr_pq.size() << endl;

    // ways to store elements in reverse order
    cout << "............................" << endl;
    priority_queue<int> pq;
    // do negation and insert
    pq.push(-1);
    pq.push(-5);
    pq.push(-2);
    pq.push(-6);
    // this way we can make a min. priority_queue using a max. one
    cout << -1*pq.top() << endl; // while extracting do negation again

    // minimum priority_queue
    cout << "............................" << endl;
    priority_queue<int,vector<int>, greater<int>> mpq;
    mpq.push(1);
    mpq.push(5);
    mpq.push(2);
    mpq.push(6);

    cout << mpq.top() << endl; // prints 1

    // minimum priority_queue for pairs
    cout << "............................" << endl;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> mpq2;
    mpq2.push({1,5});
    mpq2.push({1,6});
    mpq2.push({1,7});
    cout << mpq2.size() << endl;
    cout << mpq2.top().first << " " << mpq2.top().second << endl;

    cout << "............................" << endl;
    cout << "Dequeue" << endl;
    deque<int> dq;
    // push_front()
    // push_back()
    // pop_front()
    // pop_back()
    // begin, end, rbegin, rend
    // size(), clear(), empty(), at()
    dq.push_back(10); // 10
    dq.push_front(20); // 20 10
    dq.push_back(30); // 20 10 30
    dq.pop_front(); // 10 30
    for(auto it: dq){
        cout << it << " ";
    }

    cout << "............................" << endl;
    cout << "List" << endl;
    list<int> ls;  // it uses DLL
    // push_front()
    // push_back()
    // pop_front()
    // pop_back()
    // begin, end, rbegin, rend
    // size(), clear(), empty(), at()
    // remove() -> O(1)
    ls.push_front(1);
    ls.push_front(2);
    ls.push_front(3);
    ls.push_front(4); // 4 3 2 1
    ls.remove(2); // O(1) operation

    for(auto it: ls){
        cout << it << " ";
    }
    return 0;
}