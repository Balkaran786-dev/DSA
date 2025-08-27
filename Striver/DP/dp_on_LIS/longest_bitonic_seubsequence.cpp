
//since peak is also changing , we need to take that also in the dp vector....


int helper(int peak, int idx, int prev_idx, int n, vector<int>& arr, vector<vector<vector<int>>> &dp) {
    if (idx == n) return 0;

    if (dp[peak][idx][prev_idx + 1] != -1) return dp[peak][idx][prev_idx + 1];

    int maxi = 0;
 
    maxi = max(maxi, helper(peak, idx + 1, prev_idx, n, arr, dp));

    if (prev_idx == -1 || (arr[idx] > arr[prev_idx] && peak == 0)) {
        maxi = max(maxi, 1 + helper(peak, idx + 1, idx, n, arr, dp));
    } else if (arr[idx] < arr[prev_idx]) {
        maxi = max(maxi, 1 + helper(1, idx + 1, idx, n, arr, dp)); 
    }

    return dp[peak][idx][prev_idx + 1] = maxi;
}

int longestBitonicSubsequence(vector<int>& arr, int n) {
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
    return helper(0, 0, -1, n, arr, dp);
}



//Note : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        
        //LIS
        for(int i=1;i<n;i++){
            int maxi=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    maxi=max(maxi,dp1[j]);
                }
            }
            dp1[i]+=maxi;
        }
        
        
        //LDS
        for(int i=n-2;i>=0;i--){
            int maxi=0;
            for(int j=n-1;j>i;j--){
                if(nums[j]<nums[i]){
                    maxi=max(maxi,dp2[j]);
                }
            }
            dp2[i]+=maxi;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp1[i]!=1 && dp2[i]!=1) ans=max(ans,dp1[i]+dp2[i]-1);
        }
        
        return ans;
    }
};
