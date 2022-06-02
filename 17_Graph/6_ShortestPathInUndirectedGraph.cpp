/*Shortest Path in Unweighted Graph*/
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// Using BFS as it traverses from 1 node to end
void shortest(vector<int> adj[],int V,int s){
    // to store distances from node s to other nodes
    int dist[V];
    fill(dist,dist+V,INT_MAX);
    dist[s]=0; // as it is starting node
    // now modify BFS to fill dist
    queue<int> q;
    bool visited[V] = { false };
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto &x: adj[curr]){ // we will check for each adjacent of curr
            if(!visited[x]){ // if it is not visited we update dist and visited
                dist[x]=dist[curr]+1;
                visited[x]=true;
                q.push(x);
            }
        }
    }
    //Print dist[]
    for(int i=0;i<V;i++){
        cout << dist[i] << " ";
    }
}

int main(){
    int V=4;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    shortest(adj,V,0);
    return 0;
}