class Solution {
public:
    int MOD = 1e9 + 7;
    int f(int i, int j, string& s, string& str, vector<vector<int>>& dp,
          int n) {
        if (j == 5)
            return 1;
        if (i == n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        ans = f(i + 1, j, s, str, dp, n);
        if (s[i] == str[j] || str[j]=='*')
            ans = (ans + f(i + 1, j + 1, s, str, dp, n)) % MOD;
        return dp[i][j] = ans;
    }
    int countPalindromes(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {                
                    string str = to_string(i) + to_string(j) + "*"+
                                 to_string(j) + to_string(i);
                    vector<vector<int>> dp(n, vector<int>(5, -1));
                    ans = (ans + f(0, 0, s, str, dp, n)) % MOD;
            }
        }
        return ans;
    }
};