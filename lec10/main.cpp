#include <iostream>
#include <queue>
#include <vector>
using namespace std;



class Graph {
    int v;
    vector<vector<int>>  adj;

public:
    Graph(int vertices) {
        v = vertices;
        adj.resize(v);
    }


    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }

    void BFS(int start) {

        vector<bool> visited(v, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;


        cout << "BFS Traversal starting from vertex " << start << ":\n";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            cout << current << " ";
             
            for (int i = 0; i < adj[current].size(); i++) {
                int u = adj[current][i];
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }

        }

        cout << endl;
    }



    void BFS(int start) {
        vector<bool> visited(v, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int current = q.front(); // H
            q.pop();

            for (int i = 0; i < adj[current].size(); i++) {

                int u = adj[current][i];

                if (!visited[u]) {
                    q.push(u);
                    visited[u] = true;
                }

            }
        }


        // [h] = true; 
    }


    void bfs_path(int start) {
        vector<int> dist(v, -1);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();


            for (int neighbor : adj[current]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[current] + 1;
                    q.push(neighbor);
                }
            }
        }

        for (int i = 0; i < dist.size(); i++) {
            cout << i << " " << dist[i] << endl;
        }

    }


};


int main () {

    Graph g(6);
    
    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    

    /*
    
    

        0
       / \
      1   2
     / \
    3   4
    |
    5


    start = 0

    0 - 0
    1 - 1
    2 - 1
    3 - 2
    4 - 2
    5 - 3


    */

    
    g.BFS(0);

    g.bfs_path(0);


    return 0;
}