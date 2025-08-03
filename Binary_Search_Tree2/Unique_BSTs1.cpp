// here , value of nodes pe depend nhi krta question,
// only number of nodes pe depend kr rha hai,,,
// f(k) -> return number of unique BSTs with k nodes.
// see the dry run for n=4;


class Solution {
    public:
        int helper(int i,vector<int> &dp){
            if(i==0 || i==1) return 1;
    
            if(dp[i]!=-1) return dp[i];
    
            int trees=0;
            for(int k=1;k<=i;k++){
               trees+=(helper(k-1,dp)*helper(i-k,dp));
            }
            return dp[i]=trees;
        }
        int numTrees(int n) {
            vector<int> dp(n+1,-1);
            return helper(n,dp);
        }
    };
