class Solution {
public:
    int get_cost(int prev_idx,int idx,vector<int>& nums,vector<vector<int>> &dp,int n){
        if(idx==n) return nums[prev_idx];
        if(idx==n-1) return max(nums[prev_idx],nums[idx]);

        if(dp[prev_idx][idx]!=-1) return dp[prev_idx][idx];

        int op1=max(nums[prev_idx],nums[idx])+get_cost(idx+1,idx+2,nums,dp,n);
        int op2=max(nums[idx],nums[idx+1])+get_cost(prev_idx,idx+2,nums,dp,n);
        int op3=max(nums[prev_idx],nums[idx+1])+get_cost(idx,idx+2,nums,dp,n);

        return dp[prev_idx][idx]=min({op1,op2,op3});
    }

    int minCost(vector<int>& nums) {
        int n=nums.size();
        int prev_idx=0,idx=1;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return get_cost(prev_idx,idx,nums,dp,n);
    }
};