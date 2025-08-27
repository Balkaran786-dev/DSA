//tabulation using unordered_map due to arise of negative ele

class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
            int n=nums.size();
            vector<unordered_map<int,int>> dp(n+1);
    
            dp[n][0]=1;
    
            for(int i=n-1;i>=0;i--){
                for(auto ele:dp[i+1]){
                    dp[i][ele.first+nums[i]]+=ele.second; 
                    dp[i][ele.first-nums[i]]+=ele.second;
                }
            }
    
            return dp[0][target];
        }
    };