class Solution {
public:
    using pp = pair<long long,int>;
    int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {

        int m=roads.size();
        vector<vector<pair<int, int>>> adj(n);
  
        for (int i = 0; i < m; i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<long long> distance(n,LLONG_MAX);
        vector<int> ways(n,0);
        ways[0]=1;
        distance[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            pp curr = pq.top();
            pq.pop();
            long long dist = curr.first;
            int node = curr.second;
            if(node==n-1) continue;
            for (auto ele : adj[node]) {
                int neigh = ele.first;
                int wt = ele.second;
                if (dist + wt< distance[neigh]) {
                    ways[neigh]=ways[node];
                    distance[neigh] = dist + wt;
                    pq.push({dist + wt, neigh});
                }
                else if(dist + wt == distance[neigh]){
                    ways[neigh]=(ways[neigh]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};