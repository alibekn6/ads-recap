#include <iostream>
#include <vector>
using namespace std;



class Graph {


    int v;
    vector<vector<int>> adj;
    vector<bool> visited;

public:

    Graph(int v) {
        this->v = v;
        adj.resize(v);
        visited.resize(v, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int source) {
        visited[source] = true;
        cout << source << " ";

        for (int i = 0; i < adj[source].size(); i++) {
            int u = adj[source][i];
            if (!visited[u]) {
                DFS(u);
            }
        }
    }

};


int main() {


}