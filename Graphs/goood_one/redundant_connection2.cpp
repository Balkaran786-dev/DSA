class Solution {
public:
    int find(vector<int>& par, int x) {
        return par[x] = (par[x] == x ? x : find(par, par[x]));
    }
    bool Union(vector<int>& par, vector<int>& rank, int a, int b) {
        a = find(par, a);
        b = find(par, b);
        if (a == b)
            return true;
        if (rank[a] <= rank[b]) {
            par[a] = b;
            rank[b]++;
        } else {
            par[b] = a;
            rank[a]++;
        }
        return false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = INT_MIN;
        for (int i = 0; i < edges.size(); i++) {
            n = max(n, edges[i][0]);
            n = max(n, edges[i][1]);
        }

        int b1 = -1, b2 = -1;
        vector<int> inward(n + 1, -1);
        for (int i = 0; i < edges.size(); i++) {
            if (inward[edges[i][1]] != -1) {
                b1 = i;
                b2 = inward[edges[i][1]];
                break;
            } else {
                inward[edges[i][1]] = i;
            }
        }
       
        vector<int> par(n + 1);
        vector<int> rank(n + 1, 1);
        for (int i = 0; i <= n; i++)
            par[i] = i;

        if (b1 == -1) { // means no 2 parents , only cycle is presnt
            int i = 0;
            while (i < edges.size()) {
                int a = edges[i][0];
                int b = edges[i][1];
                if (Union(par, rank, a, b)) {
                    return {a, b};
                }
                i++;
            }
        } else {
            int i = 0;
            while (i < edges.size()) {
                int a = edges[i][0];
                int b = edges[i][1];
                if (i != b1 && Union(par, rank, a, b)) {
                    return {edges[b2][0], edges[b2][1]};
                }
                i++;
            }
            return {edges[b1][0], edges[b1][1]};
        }
        return {};
    }
};