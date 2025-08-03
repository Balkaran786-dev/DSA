#include <bits/stdc++.h>
using namespace std;

// Function to find the shortest path using BFS
vector<int> shortestPathBFS(vector<vector<int>> &adj, int start, int end, int n) {
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        if (node == end) break;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    
    vector<int> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    
    if (path[0] != start) return {};
    return path;
}

// Function to find the shortest path using DFS
void dfs(int node, int end, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &currentPath, vector<int> &shortestPath) {
    visited[node] = true;
    currentPath.push_back(node);
    
    if (node == end) {
        if (shortestPath.empty() || currentPath.size() < shortestPath.size()) {
            shortestPath = currentPath;
        }
    } else {
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, end, adj, visited, currentPath, shortestPath);
            }
        }
    }
    
    visited[node] = false;
    currentPath.pop_back();
}

vector<int> shortestPathDFS(vector<vector<int>> &adj, int start, int end, int n) {
    vector<bool> visited(n, false);
    vector<int> currentPath, shortestPath;
    dfs(start, end, adj, visited, currentPath, shortestPath);
    return shortestPath;
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
    }
    
    int start, end;
    cout << "Enter start and end nodes: ";
    cin >> start >> end;
    
    vector<int> pathBFS = shortestPathBFS(adj, start, end, n);
    vector<int> pathDFS = shortestPathDFS(adj, start, end, n);
    
    if (!pathBFS.empty()) {
        cout << "Shortest path using BFS: ";
        for (int node : pathBFS) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found using BFS between " << start << " and " << end << endl;
    }
    
    if (!pathDFS.empty()) {
        cout << "Shortest path using DFS: ";
        for (int node : pathDFS) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found using DFS between " << start << " and " << end << endl;
    }
    return 0;
}



