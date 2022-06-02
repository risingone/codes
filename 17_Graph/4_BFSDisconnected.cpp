#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        cout << i << ": ";
        for(int x: adj[i]){
            cout << x <<" ";
        }
        cout << endl;
    }
}

// normal BFS for connected
void BFS(vector<int> adj[],int i,bool visited[]){
    queue<int> q;
    visited[i]=true;
    q.push(i);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v: adj[u]){
            if(visited[v]==false){
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

// BFS disconnected
int BFSDis(vector<int> adj[],int v){
    int count=0;
    bool visited[v+1]={ false };
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            BFS(adj,i,visited);
            count++;
        }
    }
    return count;
}

int main(){
    int V=9;
    vector<int> adj[V];
    /*
       0    3     5
      / \   |    / \
     1---2  4   6   7
                    |
                    8
    */
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,3,4);
    addEdge(adj,5,6);
    addEdge(adj,5,7);
    addEdge(adj,7,8);
    printGraph(adj,V);
    cout << "BFS: ";
    int numDisconnected = BFSDis(adj,V);
    cout << endl;
    cout << "No. of disconnected Graph Components: " << numDisconnected << endl;
    return 0;
}