#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v){
    for(int i=0;i<v;i++){
        cout << i <<": ";
        for(int x: adj[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main(){
    int V=4; // 4 vertex
    vector<int> adj[V]; // array of vectors
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    printGraph(adj,V);
    return 0;
}