
//since peak is also changing , we need to take that also in the dp vector....


int helper(int peak, int idx, int prev_idx, int n, vector<int>& arr, vector<vector<vector<int>>> &dp) {
    if (idx == n) return 0;

    if (dp[peak][idx][prev_idx + 1] != -1) return dp[peak][idx][prev_idx + 1];

    int maxi = 0;

   
    maxi = max(maxi, helper(peak, idx + 1, prev_idx, n, arr, dp));

    if (prev_idx == -1 || (arr[idx] > arr[prev_idx] && peak == 0)) {
        maxi = max(maxi, 1 + helper(peak, idx + 1, idx, n, arr, dp));
    } else if (arr[idx] < arr[prev_idx]) {
        if (peak == 0) {
            maxi = max(maxi, 1 + helper(1, idx + 1, idx, n, arr, dp)); 
        } else {
            maxi = max(maxi, 1 + helper(peak, idx + 1, idx, n, arr, dp));
        }
    }

    return dp[peak][idx][prev_idx + 1] = maxi;
}

int longestBitonicSubsequence(vector<int>& arr, int n) {
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
    return helper(0, 0, -1, n, arr, dp);
}
