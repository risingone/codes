#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool recDFS(vector<int> adj[],int i,bool visited[],int parent){
    visited[i]=true;
    for(auto &x: adj[i] ){
        if(!visited[x]){
            if(recDFS(adj,x,visited,i)){
                return true;
            }
        }
        else if(x!=parent){
            return true;
        }
    }
    return false;
}

bool DFS(vector<int> adj[],int V){
    bool visited[V]={ false };
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(recDFS(adj,i,visited,-1)==true){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int V=4;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    cout << DFS(adj,V) << endl;
    return 0;
}