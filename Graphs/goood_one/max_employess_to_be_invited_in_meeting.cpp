class Solution {
public:
    int BFS(int start, unordered_map<int, vector<int>>& adj,
            vector<bool>& visited) {
        queue<pair<int, int>> que; // {node, path length}
        que.push({start, 0});
        int maxDistance = 0;

        while (!que.empty()) {
            auto [currNode, dist] = que.front();
            que.pop();

            for (auto& ngbr : adj[currNode]) {
                if (!visited[ngbr]) {
                    visited[ngbr] = true;
                    que.push({ngbr, dist + 1});
                    maxDistance = max(maxDistance, dist + 1);
                }
            }
        }

        return maxDistance;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            int u = i;
            int v = favorite[i];
            // u->v
            adj[v].push_back(u); // reverse graph - so that we can find the path
                                 // length after the traversal
        }

        int longestCycleEmpCount = 0;
        int happyCoupleEmpCount =
            0; // cycle length =2 wallo se kitna milpaega total
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                // we will store two things at evry node, {konsa node , abtak ka
                // node count}
                unordered_map<int, int> mp;
                int currNode = i;
                int currNodeCount = 0;

                while (!visited[currNode]) { // until a cycle gets detected.
                    visited[currNode] = true;
                    mp[currNode] = currNodeCount;

                    int nextNode =
                        favorite[currNode]; // favorite node of curr node
                    currNodeCount += 1;

                    if (mp.count(nextNode)) { // already visited hai ye.Matlab
                                              // cycle detect hogaya hai
                        int cycleLength = currNodeCount - mp[nextNode];
                        longestCycleEmpCount =
                            max(longestCycleEmpCount, cycleLength);
                        if (cycleLength == 2) { // happy couple case.
                            // currNode <-> nextNode = 2 nodes..
                            vector<bool> visitedNodes(n, false);
                            visitedNodes[nextNode] = true;
                            visitedNodes[currNode] = true;
                            happyCoupleEmpCount +=
                                2 + BFS(currNode, adj, visitedNodes) +
                                BFS(nextNode, adj, visitedNodes);
                        }
                        break;
                    }
                    currNode = nextNode;
                }
            }
        }
        return max(longestCycleEmpCount, happyCoupleEmpCount);
    }
};