#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Disjoint Set Union (Union-Find)
class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return false;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

// Kruskal's Algorithm
void kruskal(int V, vector<Edge>& edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    DisjointSet ds(V);
    int mstWeight = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (Edge e : edges) {
        if (ds.unite(e.u, e.v)) {
            cout << e.u << " - " << e.v
                 << " (weight = " << e.weight << ")\n";
            mstWeight += e.weight;
        }
    }

    cout << "Total weight of MST = " << mstWeight << endl;
}

int main() {
    int V = 4; // number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(V, edges);
    return 0;
}
