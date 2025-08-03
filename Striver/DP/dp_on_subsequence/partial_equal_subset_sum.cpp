// very similar to subset sum here, we need to find the subset with target equal half of total sum if the total sum is even...

class Solution {
    public:
        bool subset_sum(vector<int>& nums,int idx,int target,int n,vector<vector<int>> &dp){
            if(target==0) return true;
            if(idx==n || target<0){
                return false;
            }
            if(dp[idx][target]!=-1) return dp[idx][target];
    
            bool take=subset_sum(nums,idx+1,target-nums[idx],n,dp);
            bool not_take=subset_sum(nums,idx+1,target,n,dp);
    
            return dp[idx][target]=take||not_take;
        }
        bool canPartition(vector<int>& nums) {
            int n=nums.size();
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=nums[i];
            }
            if(sum%2!=0) return false;
    
            int target=sum/2;
            vector<vector<int>> dp(n,vector<int> (target+1,-1));
            return subset_sum(nums,0,target,n,dp);
        }
    };