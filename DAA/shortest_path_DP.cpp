#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Representing "infinity"

void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist = graph; // Initialize distance matrix

    // Main DP logic
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Print result
    cout << "Shortest distances between all pairs:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<int>> graph = {
        {0,     5,   INF,   10},
        {INF,   0,     3,   INF},
        {INF, INF,     0,     1},
        {INF, INF,  INF,     0}
    };

    floydWarshall(graph, V);
    return 0;
}
