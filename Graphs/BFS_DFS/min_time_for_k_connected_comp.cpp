class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> &graph,int node, unordered_set<int>& visited,int &mid) {
        visited.insert(node);
        for (auto neighbour : graph[node]) {
            if (not visited.count(neighbour.first) && neighbour.second>mid) {
                dfs(graph,neighbour.first, visited,mid);
            }
        }
    }
    bool f(int mid, vector<vector<pair<int,int>>> &graph, int k) {
        int comp = 0;
        int n = graph.size();
        unordered_set<int> visited;
        for (int i = 0; i < n; i++) {
            if (visited.count(i) == 0) {
                comp++;
                if(comp>=k) return true;
                dfs(graph,i,visited,mid);
            }
        }
        if(comp>=k) return true;
        return false;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        
        vector<vector<pair<int,int>>> graph(n);
        int hi=0;
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            hi=max(hi,edges[i][2]);
        }
        int lo = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (f(mid, graph, k)) {
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        return lo;
    }
};