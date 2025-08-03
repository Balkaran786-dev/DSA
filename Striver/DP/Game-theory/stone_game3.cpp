class Solution {
public:
    //similar to stone game 1
    
    int f(int i,int n,int turn,vector<int>& stoneValue,vector<vector<long long>> &dp){
        if(i>=n) return 0;
        if(dp[i][turn]!=-1) return dp[i][turn];

        int result;
        if (turn == 1) {
            // Alice's turn: maximize  score
            result = INT_MIN;
            int sum = 0;
            for (int j = 0; j < 3 && i + j < n; j++) {
                sum += stoneValue[i + j];
                result = max(result, sum + f(i + j + 1, n, 0, stoneValue, dp));
            }
        } else {
            // Bob's turn: maximize his score (minimize Alice's score)
            result = INT_MAX;
            int sum = 0;
            for (int j = 0; j < 3 && i + j < n; j++) {
                sum += stoneValue[i + j];
                result = min(result, -sum + f(i + j + 1, n, 1, stoneValue, dp));
            }
        }
        return dp[i][turn] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<long long>> dp(n,vector<long long> (2,-1));
        int turn=1;
        int ans=f(0,n,turn,stoneValue,dp);
        if(ans==0) return "Tie";
        else if(ans>0) return "Alice";
        return "Bob";
    }
};