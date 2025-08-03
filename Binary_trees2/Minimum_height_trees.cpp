//BRUTE FORCE
//DFS from all nodes,
// got height less than previous, remove everything from ans and put that node in ans,
//if got same height just push that node in ans,
//if got greater height, do nothing with that node.




//Topological sort on unordered edges...
//that MHT node will always be on diameter, and it will be at most 2,
//so, while traversing whatever is there in my queue im going to deduct that many nodes from remaing, until it is <2,

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        // Build graph and degree
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> q;

        // Push all leaf nodes (degree == 1)
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) q.push(i);
        }

        // Trim leaves level by level
        int remaining = n;
        while (remaining > 2) {
            int sz = q.size();
            remaining -= sz;
            while (sz--) {
                int node = q.front(); q.pop();
                for (int neighbor : graph[node]) {
                    if (--degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // Remaining nodes are the root(s) of MHT
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};
