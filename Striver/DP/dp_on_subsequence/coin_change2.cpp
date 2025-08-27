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


//coin change 1
//tabulation
#include <bits/stdc++.h>
using namespace std;

int minimumElements(vector<int> &num, int x) {
    int n = num.size();
    vector<vector<int>> dp(n+1, vector<int>(x+1, INT_MAX));

    // Base case
    for (int j = 0; j <= x; j++) {
        if (j == 0) dp[n][j] = 0;
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j <= x; j++) {
            if (j == 0) {
                dp[i][j] = 0;
                continue;
            }

            int not_take = dp[i+1][j];
            int take = INT_MAX;
            if (j >= num[i] && dp[i][j - num[i]] != INT_MAX) {
                take = 1 + dp[i][j - num[i]];
            }

            dp[i][j] = min(take, not_take);
        }
    }

    return (dp[0][x] == INT_MAX ? -1 : dp[0][x]);
}
