class Solution {
public:
    int dfs(int emp, vector<vector<int>>& adj, vector<int>& informTime) {
        int maxTime = 0;
        for (int sub : adj[emp]) {
            maxTime = max(maxTime, dfs(sub, adj, informTime));
        }
        return informTime[emp] + maxTime;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        return dfs(headID, adj, informTime);
    }
};
