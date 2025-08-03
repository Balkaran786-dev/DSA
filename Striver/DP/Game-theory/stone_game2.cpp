class Solution {
public:
    // the function returns the alex score..
    //when its alex turn, beacuse she is calculating her score, she adds the chosen stones and move on and expects a maximum ans, as she is trying to maximise her score..
    //when its bob turn, he can't contribute to the score,but he can expect teh worst for alex, so he expects min out of it.
    // this has been done so that bob also play optimallyy.
    
    int get_stone(int i,int M,int n,int turn,vector<int>& piles,vector<vector<vector<int>>> &dp,vector<int> &prefix){
        if(i>=n) return 0;
        if(dp[i][M][turn]!=-1) return dp[i][M][turn];
        
         if (turn) { // Player A (maximizer)
            int maxStones = 0;
            for (int X = 1; X <= 2 * M && i + X <= n; ++X) {
                int taken = prefix[i + X - 1] - (i > 0 ? prefix[i - 1] : 0);
                maxStones = max(maxStones, taken + get_stone(i + X, max(M, X), n, 0, piles, dp, prefix));
            }
            return dp[i][M][turn] = maxStones;
        } else { // Player B (minimizer)
            int minStones = INT_MAX;
            for (int X = 1; X <= 2 * M && i + X <= n; ++X) {
                minStones = min(minStones, get_stone(i + X, max(M, X), n, 1, piles, dp, prefix));
            }
            return dp[i][M][turn] = minStones;
        } 
        return 0;
    }

    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (202,vector<int> (2,-1)));
        int turn=1;
        vector<int> prefix(n);
        prefix[0]=piles[0];
        for(int i=1;i<n;i++){
            prefix[i]=piles[i]+prefix[i-1];
        }
        return get_stone(0,1,n,turn,piles,dp,prefix);
    }
};