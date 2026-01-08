#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V, INT_MAX));
    for (int i = 0; i < V; i++) graph[i][i] = 0;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> inMST(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1, mn = INT_MAX;
        for (int i = 0; i < V; i++) {
            if (!inMST[i] && key[i] < mn) {
                mn = key[i];
                u = i;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INT_MAX && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " " << i << " " << graph[i][parent[i]] << "\n";
        total += graph[i][parent[i]];
    }

    cout << total << "\n";
    return 0;
}
