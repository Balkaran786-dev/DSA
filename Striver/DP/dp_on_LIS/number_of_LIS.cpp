class Solution {
    public:
        int findNumberOfLIS(vector<int>& nums) {
            int n=nums.size();
            vector<pair<int,int>> dp(n,{1,1});  // pair.first - size of LIS till that index , pair.second - how many LIS till that index
            for(int i=1;i<n;i++){
                int maxi=0;
                int count=1;
                for(int j=0;j<i;j++){
                    if(nums[i]>nums[j]){
                        if(dp[j].first>maxi){
                            count=dp[j].second;
                            maxi=dp[j].first;
                        }
                        else if(dp[j].first==maxi){
                            count+=dp[j].second;
                        }
                    }
                }
                dp[i].first+=maxi;
                dp[i].second=count;
            }
            
            int maxi=0;
            for(int i=0;i<n;i++){
                maxi=max(maxi,dp[i].first);
            }
            
            int count=0;
            for(int i=0;i<n;i++){
               if(maxi==dp[i].first){
                count+=dp[i].second;
               }
            }
    
            return count;
        }
    };