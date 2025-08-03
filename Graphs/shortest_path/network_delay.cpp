//simple dijkstra


class Solution {
public:
    using pp=pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int m=times.size();
        vector<vector<pair<int, int>>> adj(n + 1);
  
        for (int i = 0; i < m; i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v, wt});
        }
        
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            pp curr = pq.top();
            pq.pop();
            int dist = curr.first;
            int node = curr.second;
            for (auto ele : adj[node]) {
                int neigh = ele.first;
                int wt = ele.second;
                if (dist + wt < distance[neigh]) {
                    distance[neigh] = dist + wt;
                    pq.push({dist + wt, neigh});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX) return -1;
            maxi=max(maxi,distance[i]);
        }
        return maxi;
        
    }
};