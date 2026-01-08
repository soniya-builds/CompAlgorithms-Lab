#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int find(int x, vector<int>& parent) {
    if (parent[x] != x)
        parent[x] = find(parent[x], parent);
    return parent[x];
}

void unite(int x, int y, vector<int>& parent, vector<int>& rank) {
    x = find(x, parent);
    y = find(y, parent);
    if (x != y) {
        if (rank[x] < rank[y]) parent[x] = y;
        else if (rank[x] > rank[y]) parent[y] = x;
        else {
            parent[y] = x;
            rank[x]++;
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int total = 0;
    for (auto e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            unite(e.u, e.v, parent, rank);
            cout << e.u << " " << e.v << " " << e.w << "\n";
            total += e.w;
        }
    }

    cout << total << "\n";
    return 0;
}
