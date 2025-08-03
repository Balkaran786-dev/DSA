#include <bits/stdc++.h> 
using namespace std; 
 
// Check if vertex v can be added to path at position pos 
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) { 
    if (!graph[path[pos - 1]][v]) return false; 
 
    for (int i = 0; i < pos; i++) 
        if (path[i] == v) return false; 
 
    return true; 
} 
 
// Recursive utility to find the Hamiltonian cycle 
bool hamCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos) { 
    if (pos == graph.size()) { 
        return graph[path[pos - 1]][path[0]] == 1; 
    } 
 
    for (int v = 1; v < graph.size(); v++) { 
        if (isSafe(v, graph, path, pos)) { 
            path[pos] = v; 
            if (hamCycleUtil(graph, path, pos + 1)) 
                return true; 
            path[pos] = -1; // Backtrack 
        } 
    } 
 
    return false; 
} 
 
 
int main() { 
    int n; 
    cout << "Enter number of vertices: "; 
    cin >> n; 
 
    vector<vector<int>> graph(n, vector<int>(n)); 
    cout << "Enter adjacency matrix:\n"; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> graph[i][j]; 
 
    vector<int> path(n, -1); 
    path[0] = 0; 
 
    if (hamCycleUtil(graph, path, 1)) { 
        cout << "Hamiltonian Cycle found:\n"; 
        for (int i = 0; i < n; i++) 
            cout << path[i] << " "; 
        cout << path[0] << endl; // to complete the cycle 
 
 
 
    } else { 
        cout << "No Hamiltonian Cycle exists.\n"; 
    } 
 
    return 0; 
} 