// shortest path using BFS in undirected graph

#include <bits/stdc++.h>
using namespace std;

// Function to find the shortest path using BFS
vector<int> shortestPath(vector<vector<int>> &adj, int start, int end, int n) {
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        if (node == end) break; // Stop BFS when we reach the destination
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    
    // Reconstruct the path from end to start
    vector<int> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    
    if (path[0] != start) return {}; // No path found
    return path;
}

int main() {
    int n, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> edges;
    
    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int start, end;
    cout << "Enter start and end nodes: ";
    cin >> start >> end;
    
    vector<int> path = shortestPath(adj, start, end, n);
        
    if (!path.empty()) {
        cout << "Shortest path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found between " << start << " and " << end << endl;
    }
    return 0;
}
