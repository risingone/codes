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
// Recursive function
void DFSRec(vector<int> adj[],int s,bool visited[]){
    visited[s]=true;
    cout << s << " ";
    for(int x: adj[s]){
        if(!visited[x]){
            DFSRec(adj,x,visited);
        }
    }
}
// TC: O(V+E)
// In case various disconnected graphs are present
int DFS(vector<int> adj[],int v){
    int count=0;
    bool visited[v]={ false };
    for(int i=0;i<v;i++){
        if(!visited[i]){
            DFSRec(adj,i,visited);
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
    cout << "DFS: ";
    int res = DFS(adj,V);
    cout << "\nNo. of different components: " << res << endl;
    return 0;
}