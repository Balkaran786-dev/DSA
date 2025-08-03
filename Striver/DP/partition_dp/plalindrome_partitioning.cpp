class Solution {
    public:
        bool is_palindrome(string &s, int start, int end) {
            while (start < end) {
                if (s[start++] != s[end--]) return false;
            }
            return true;
        }
    
        int get_cuts(int i, int j, string &s, vector<int> &dp) {
            if (i == j || is_palindrome(s, i, j)) return 0;
    
            if (dp[i] != -1) return dp[i];
    
            int mini = INT_MAX;
    
            for (int k = i; k < j; k++) {
                if (is_palindrome(s, i, k)) {
                    int cuts = 1 + get_cuts(k + 1, j, s, dp);
                    mini = min(mini, cuts);
                }
            }
    
            return dp[i] = mini;
        }
    
        int minCut(string s) {
            int n = s.size();
            vector<int> dp(n, -1);
            return get_cuts(0, n - 1, s, dp);
        }
    };
    