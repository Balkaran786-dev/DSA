class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string,double>>>& mp, string src,
             string dst, unordered_set<string>& visited, double product,
             double& ans) {
        if (visited.count(src))
            return;
        
        visited.insert(src);
        if (src == dst) {
            ans = product;
            return;
        }
        for (auto ele:mp[src]) {
            dfs(mp, ele.first, dst, visited, product * ele.second, ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        for (int i = 0; i < equations.size(); i++) {
            string str1 = equations[i][0], str2 = equations[i][1];

            double val = values[i];

            mp[str1].push_back({str2, val});
            mp[str2].push_back({str1, 1.0 / val});
        }

        int q = queries.size();
        vector<double> result(q);
        for (int i = 0; i < q; i++) {
            string src = queries[i][0];
            string dst = queries[i][1];

            double ans = -1.0;
            double product = 1.0;
            unordered_set<string> visited;
            if (mp.find(src) != mp.end() && mp.find(dst) != mp.end()) {
                dfs(mp, src, dst, visited, product, ans);
            }
            result[i] = ans;
        }
        return result;
    }
};