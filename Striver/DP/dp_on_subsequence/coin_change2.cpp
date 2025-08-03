class Solution {
    public:
        int get_comb(vector<int> &coins,int idx,int amount,vector<vector<int>> &dp,int n){
            
            if(idx==n-1){
                if(amount==0) return 1;
                if(amount%coins[n-1]==0) return 1;
                return 0;
            }
    
            if(dp[idx][amount]!=-1) return dp[idx][amount];
            int not_take=get_comb(coins,idx+1,amount,dp,n);
            int take=0;
            if(amount>=coins[idx]){
                take=get_comb(coins,idx,amount-coins[idx],dp,n);
            }
            return dp[idx][amount]=take+not_take;
        }
        int change(int amount, vector<int>& coins) {
            int n=coins.size();
            vector<vector<int>> dp(n,vector<int> (amount+1,-1));
            int idx=0;
            return get_comb(coins,idx,amount,dp,n);
        }
    };