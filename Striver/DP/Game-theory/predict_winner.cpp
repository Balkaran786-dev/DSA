class Solution {
public:
    //similar to stone game 1
    int f(int i,int j,int turn,vector<int>& nums,vector<vector<vector<int>>> &dp){
        if(i==j){
            if(turn==1) return nums[i];
            return -nums[i];
        }
        if(dp[i][j][turn]!=-1) return dp[i][j][turn];
        int result;
        if(turn==1){
            result=max(nums[i]+f(i+1,j,0,nums,dp),nums[j]+f(i,j-1,0,nums,dp));
        }
        else result=min(-nums[i]+f(i+1,j,1,nums,dp),-nums[j]+f(i,j-1,1,nums,dp));
        return dp[i][j][turn] = result;
    }

    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int> (2,-1)));
        int i=0,j=n-1;
        int turn=1;
        int ans=f(i,j,turn,nums,dp);
        if(ans>=0) return true;
        return false;
    }
};