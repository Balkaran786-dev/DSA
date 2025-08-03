
class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[2] < v2[2];
    }

    int find(int x, vector<int>& par) {
        return par[x] = (par[x] == x) ? x : find(par[x], par);
    }

    bool Union(int a, int b, vector<int>& par, vector<int>& rank) {
        a = find(a, par);
        b = find(b, par);
        if (a == b)
            return false;
        if (rank[a] < rank[b]) {
            par[a] = b;
        } else if (rank[a] > rank[b]) {
            par[b] = a;
        } else {
            par[a] = b;
            rank[b]++;
        }
        return true;
    }

    int kruskal(vector<vector<int>>& edges, int remove, int V , int add) {
        vector<int> par(V), rank(V, 0);
        for (int i = 0; i < V; ++i)
            par[i] = i;

        int totalWeight = 0, edgeCount = 0;
        if (add != -1) {
            Union(edges[add][0], edges[add][1], par, rank);
            totalWeight += edges[add][2];
            edgeCount++;
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == remove)
                continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            if (edgeCount == V - 1)
                break;
            if (Union(u, v, par, rank)) {
                totalWeight += wt;
                edgeCount++;
            }
        }

        return edgeCount == V - 1 ? totalWeight : 1e9;  // Ensure MST is complete  //may be jo humne edge remove kiya hai voh bridge ho and that can make our graph disconnected, so we need ut , hence it is critical.
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int edg = edges.size();
        
        // Add original indices
        for (int i = 0; i < edg; ++i) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), cmp);
        int MST_wt = kruskal(edges, -1, n , -1);

        vector<vector<int>> ans(2);  // [critical, pseudo-critical]

        for (int i = 0; i < edg; i++) {
            int withoutEdge = kruskal(edges, i, n, -1);  //agr htane se increase hua, means critical, agr htane se same rha, than it 
            //can be a pseudo but we can't be sure, may the edge was never in any of the MST, do to make it sure, we will add this edge and then check if the 
            //the wt remains same, then it is pseudo critical, otherwise, its nothing.
            
            if (withoutEdge > MST_wt) {
                ans[0].push_back(edges[i][3]);  // Critical
            } else {
                int withEdge = kruskal(edges, i, n, i);
                if (withEdge == MST_wt)
                    ans[1].push_back(edges[i][3]);  // Pseudo-critical
            }
        }
        return ans;
    }
};
