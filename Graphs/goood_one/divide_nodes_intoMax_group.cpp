class Solution {
public:
    bool isBipartite(int start, unordered_map<int, vector<int>>& graph,
                     vector<int>& nature) {
        int color = 0;
        queue<int> qu;
        qu.push(start);
        nature[start] = color;
        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();

            for (auto neigh : graph[curr]) {
                if (nature[neigh] == -1) {
                    nature[neigh] = !nature[curr];
                    qu.push(neigh);
                } else if (nature[neigh] == nature[curr])
                    return false;
            }
        }
        return true;
    }
    int bfs(unordered_map<int, vector<int>>& graph, int start) {
        int maxi = 0;
        unordered_set<int> st;
        st.insert(start);
        queue<int> qu;
        qu.push(start);

        while (!qu.empty()) {
            int sz = qu.size();
            while (sz--) {
                int curr = qu.front();
                qu.pop();
                for (auto neigh : graph[curr]) {
                    if (st.count(neigh) == 0) {
                        qu.push(neigh);
                        st.insert(neigh);
                    }
                }
            }
            maxi++;
        }
        return maxi;
    }
    int max_sep_group(int start,unordered_map<int, vector<int>>& graph,vector<int> &visited,vector<int> &levels){
        visited[start]=0;
        int maxi=levels[start];
        for(auto neigh:graph[start]){
            if(visited[neigh]==-1){
                maxi=max(maxi,max_sep_group(neigh,graph,visited,levels));
            }
        }
        return maxi;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> nature(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (nature[i] == -1) {
                bool res = isBipartite(i, graph, nature);
                if (!res)
                    return -1;
            }
        }

        vector<int> levels(n + 1,0);
        for (int i = 1; i <= n; i++) {
            levels[i] = bfs(graph, i);
        }

        vector<int> visited(n+1,-1);
        int ans=0;
        for(int i=1;i<=n ;i++){
            if(visited[i]==-1){
                ans+=max_sep_group(i,graph,visited,levels);
            }
        }
        return ans;
    }
};