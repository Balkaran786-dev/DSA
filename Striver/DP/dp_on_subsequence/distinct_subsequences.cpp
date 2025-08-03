// idx2 ko move hi tab krenge jab voh equal hoga tab,
// idx1 pe hum agr voh equal hai toh usko choose krke bhi dekh skte hain and usko 
// ignore krke age bhi badh skte hain.....


class Solution {
    public:
        int helper(int idx1, int idx2, string &s, string &t, vector<vector<int>> &dp) {
            if (idx2 == t.size()) return 1;     // All of t matched
            if (idx1 == s.size()) return 0;     // s exhausted before matching t
    
            if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    
            int count = 0;
    
            // Match current characters
            if (s[idx1] == t[idx2]) {
                count += helper(idx1 + 1, idx2 + 1, s, t, dp);  // Match both
            }
    
            count += helper(idx1 + 1, idx2, s, t, dp);          // Skip current char of s
    
            return dp[idx1][idx2] = count;
        }
    
        int numDistinct(string s, string t) {
            int n1 = s.size(), n2 = t.size();
            vector<vector<int>> dp(n1, vector<int>(n2, -1));
            return helper(0, 0, s, t, dp);
        }
    };
    