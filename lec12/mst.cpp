// kruskal

#include <iostream>
using namespace std;


struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};



class DSU {
    vector<int> parent;

    DSU(int n) : parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return false;
        }

        parent[b] = a;
        return true;

    }
};


int main () {


    int n = 4;  // 4 vertices

    vector<Edge> edges = {
        {0, 1, 10},  // A-B: 10
        {1, 2, 5},   // B-C: 5
        {2, 3, 15},  // C-D: 15
        {0, 3, 20},  // A-D: 20
        {0, 2, 25}   // A-C: 25
    };


    sort(edges.begin(), edges.end());


    DSU dsu(n);

    int total_cost = 0;
    vector<Edge> mst;

    

    return 0;
}