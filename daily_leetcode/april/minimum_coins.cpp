// memoization

class Solution {
    public:
        int get_coins(int idx,vector<vector<int>> &dp,vector<int>& coins,int target,int n){
            if(idx==n-1){
                if(target==0) return 0;
                else if(target%coins[idx]==0) return target/coins[idx];
                return 1e9;
            }
    
            if(dp[idx][target]!=-1) return dp[idx][target];
            
            int not_take= 0 + get_coins(idx+1,dp,coins,target,n);
            int take=INT_MAX;
            if(target>=coins[idx]){
                  take= 1 + get_coins(idx,dp,coins,target-coins[idx],n);
            }
            return dp[idx][target]=min(not_take,take);
        }
        int coinChange(vector<int>& coins, int target) {
            // infinite supplies or multiple uses vale question
            // mein hume same index par bhi rehna pdega jab tak hum use krdke,
            // ek toh hum, not atke krke agle index par ja skte hain ek hum take krke ussi index par reh skte hain(jab tak reh hua..)
    
            int n=coins.size();
            vector<vector<int>> dp(n,vector<int> (target+1,-1));
            int idx=0;
            int value = get_coins(idx,dp,coins,target,n);
            if(value>=1e9) return -1;
            return value;
        }
    };


// tabulation
// tabulation mein andr vala for loop bhi hum ulta chlgeyenge means
// memo mein hum target from target to 0 za rehe the,
// tabulation mein 0 to targrt jaynge..


class Solution {
    public:
        int coinChange(vector<int>& coins, int target) {
            int n = coins.size();
            vector<int> prev(target + 1);
            for (int i = 0; i <= target; i++) {
                if (i % coins[n - 1] == 0)
                    prev[i] = i / coins[n - 1];
                else
                    prev[i] = 1e9;
            }
    
            for (int idx = n - 2; idx >= 0; idx--) {
                vector<int> curr(target+1,0);
                for (int j = 0; j <=target; j++) {
                    int not_take = 0 + prev[j]; 
                    int take = INT_MAX;
                    if (j >= coins[idx]) {
                        take = 1 + curr[j-coins[idx]];
                    }
                    curr[j]= min(not_take, take);
                }
                prev=curr;
            }
    
            if(prev[target]>=1e9) return -1;
    
            return prev[target];
        }
    };