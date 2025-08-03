class Solution {
public:
    int get_cost(int i, int last, int neigh, vector<int>& houses, vector<vector<int>>& cost,
                 int m, int n, vector<vector<vector<int>>> &dp, int target) {

        if (neigh > target) return INT_MAX / 2;
        if (i == m) return (neigh == target) ? 0 : INT_MAX / 2;

        if (dp[i][last][neigh] != -1) return dp[i][last][neigh];

        if (houses[i] != 0) {
            int new_neigh = (houses[i] != last) ? neigh + 1 : neigh;
            return dp[i][last][neigh] = get_cost(i + 1, houses[i], new_neigh, houses, cost, m, n, dp, target);
        }

        int mini = INT_MAX / 2;
        for (int color = 1; color <= n; color++) {
            int new_neigh = (color != last) ? neigh + 1 : neigh;
            int val = get_cost(i + 1, color, new_neigh, houses, cost, m, n, dp, target);
            if (val != INT_MAX / 2) {
                mini = min(mini, cost[i][color - 1] + val);  
            }
        }

        return dp[i][last][neigh] = mini;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(target + 1, -1)));
        int res = get_cost(0, 0, 0, houses, cost, m, n, dp, target);
        return (res >= INT_MAX / 2) ? -1 : res;
    }
};

//basically, agr current color jo de rhe ho voh pechle se match nhi krega,then increase the neighbour by 1,,
