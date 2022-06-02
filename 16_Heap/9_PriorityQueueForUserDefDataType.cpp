#include<bits/stdc++.h>
using namespace std;

struct Person{
    int age;
    float ht;
    Person(int a, float h){
        age=a;
        ht=h;
    }
};

struct myCmp{
    bool operator()(Person const &p1, Person const &p2){
        return p1.ht < p2.ht;
    }
};

int main(){
    priority_queue<Person, vector<Person>, myCmp> pq;
    pq.push(Person(22,5.5));
    pq.push(Person(30,6.01));
    pq.push(Person(27,5.05));
    pq.push(Person(33,6.21));
    pq.push(Person(27,5.75));
    while(!pq.empty()){
        Person p = pq.top();
        cout << p.age <<" " << p.ht << endl;
        pq.pop();
    }
    return 0;
}