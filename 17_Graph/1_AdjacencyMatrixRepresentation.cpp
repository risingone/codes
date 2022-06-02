#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
    bool** adjMatrix;
    int numVertices;
    public:
    // Constructor to create and Initialize matrix to zero
    Graph(int numVertices){
        this->numVertices = numVertices;
        adjMatrix = new bool*[numVertices]; // array of pointers
        for(int i=0;i<numVertices;i++){
            adjMatrix[i] = new bool[numVertices];//rows of matrix
            for(int j=0;j<numVertices;j++){
                adjMatrix[i][j] = false;  // initialize rows with false
            }
        }
    }

    // Add edges
    void addEdge(int i,int j){
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }

    // Remove edges
    void removeEdge(int i,int j){
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }

    // Print the matrix
    void printMatrix(){
        for(int i=0;i<numVertices;i++){
            cout << i << " : ";
            for(int j=0;j<numVertices;j++){
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main(){
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.printMatrix();
    cout << "..........................." << endl;
    g.removeEdge(0,1);
    g.printMatrix();
    return 0;
}