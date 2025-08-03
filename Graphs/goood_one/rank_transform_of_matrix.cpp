class Solution {
public:
    int Find(vector<int>& par, int x) {
        return par[x] = (par[x] == x ? x : Find(par, par[x]));
    }
    void Union(vector<int>& par, vector<int>& rank, int a, int b) {
        a = Find(par, a);
        b = Find(par, b);
        if (a == b)
            return;
        if (rank[a] <= rank[b]) {
            par[a] = b;
            rank[b]++;
        } else {
            par[b] = a;
            rank[a]++;
        }
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> ans(m, vector<int>(n)); // ans vector

        vector<int> par(m * n);
        vector<int> rank(m * n, 1);
        for (int i = 0; i < m * n; i++)
            par[i] = i;

        for (int i = 0; i < m;
             i++) { // same values with common rows will be handled here.
            unordered_map<int, int> mp;
            for (int j = 0; j < n; j++) {
                int idx_value = i * n + j;
                int ele = matrix[i][j];
                if (mp.find(ele) != mp.end()) {
                    Union(par, rank, mp[ele], idx_value);
                } else {
                    mp[ele] = idx_value;
                }
            }
        }

        for (int j = 0; j < n;
             j++) { // same values with common columns will be handled here.
            unordered_map<int, int> mp;
            for (int i = 0; i < m; i++) {
                int idx_value = i * n + j;
                int ele = matrix[i][j];
                if (mp.find(ele) != mp.end()) {
                    Union(par, rank, mp[ele], idx_value);
                } else {
                    mp[ele] = idx_value;
                }
            }
        }

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < m; i++) { // combining the cells with common parents
            for (int j = 0; j < n; j++) {
                int idx_value = i * n + j;
                int parent = Find(par, idx_value);
                mp[parent].push_back(idx_value);
            }
        }

        // now arranging the elements their value wise
        //this has been done so that we traverse elements magnitude wise..
        //taken multimap beacuse there may be values that are same but doesn't share a common row or column, so it needs two entries in this map,one those sharing a common row or column, and one that doesn't share.
        multimap<int, vector<int>> values;
        for (auto V : mp) {
            int idx_value = V.first;
            int x = idx_value / n;
            int y = idx_value % n;
            values.insert({matrix[x][y], V.second});
        }
        
        vector<int> rows(m, 0), columns(n, 0);
        for (auto ele : values) {
            int value = ele.first;
            int maxi = 0;
            for (auto idx : ele.second) {
                int x = idx / n;
                int y = idx % n;
                maxi = max(maxi, max(rows[x], columns[y]) + 1);
            }

            for (auto idx : ele.second) {
                int x = idx / n;
                int y = idx % n;
                ans[x][y] = maxi;
                rows[x] = maxi;
                columns[y] = maxi;
            }
        }
        return ans;
    }
};