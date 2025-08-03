class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        // Space : O(V + E)
        vector<int> indegree(numCourses, 0);
        // T.C : O(E)
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v); // u --> v
            indegree[v]++;
        }

        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        } 

        unordered_map<int, unordered_set<int>> mp;
        //T.C-> o(V+E)*V
        while (!que.empty()) {
            int node = que.front();
            que.pop();

            for (auto& ngbr : adj[node]) {
                mp[ngbr].insert(node);

                // find the prerequisites of node as well and by transitivity,
                // they are prereq of ngbr node as well
                for (auto& preq : mp[node]) {
                    mp[ngbr].insert(preq);
                }

                indegree[ngbr]--;
                if (indegree[ngbr] == 0) {
                    que.push(ngbr);
                }
            }
        }

        int Q = queries.size();
        vector<bool> result(Q, false);
        for (int i = 0; i < Q; i++) {
            int src = queries[i][0];
            int dest = queries[i][1];

            bool reachable = mp[dest].contains(src);
            result[i] = reachable;
        }
        return result;
    }
};