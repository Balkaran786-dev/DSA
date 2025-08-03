class Solution {
public:
    using pp = pair<int, pair<int, int>>; // {cost, {node, time}}

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        int n = fees.size();
        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Min-heap: {cost, {node, time}}
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({fees[0], {0, 0}});

        vector<int> minCost(n, INT_MAX);
        vector<int> minTime(n, INT_MAX);
        minCost[0] = fees[0];
        minTime[0] = 0;

        while (!pq.empty()) {
            auto [cost, state] = pq.top(); pq.pop();
            int node = state.first;
            int time = state.second;

            // Early exit if destination reached
            if (node == n - 1) return cost;

            for (auto& [neigh, wt] : adj[node]) {
                int nextTime = time + wt;
                int nextCost = cost + fees[neigh];

                if (nextTime > maxTime) continue;

                if (nextCost < minCost[neigh]) {
                    minCost[neigh] = nextCost;
                    minTime[neigh] = nextTime;
                    pq.push({nextCost, {neigh, nextTime}});
                }
                else if (nextTime < minTime[neigh]) {
                    minTime[neigh] = nextTime;
                    pq.push({nextCost, {neigh, nextTime}});
                }
            }
        }

        return -1;
    }
};
