class Solution {
public:
    
    int get_value(int idx,int n,int coins,int k,vector<vector<int>>& piles,vector<vector<int>> &dp){
        if(idx==n || coins==k) return 0;
        if(dp[idx][coins]!=-1) return dp[idx][coins];

        int sum=0;
        int ans=get_value(idx+1,n,coins,k,piles,dp);
        
        for(int i=0;i<piles[idx].size();i++){
            if(coins+i+1>k) break; 
            sum+=piles[idx][i];
            int result=get_value(idx+1,n,coins+i+1,k,piles,dp);
            ans=max(ans,sum+result);
        }
        return dp[idx][coins]=ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int> (k+1,-1));
        return get_value(0,n,0,k,piles,dp);
    }
};