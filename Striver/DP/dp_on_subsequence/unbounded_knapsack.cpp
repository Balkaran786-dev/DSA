int get_profit(int idx,int w,vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp,int n){
    if(idx==n){
       return 0
    }

    if(dp[idx][w]!=-1) return dp[idx][w];

    int not_take=get_profit(idx+1,w,profit,weight,dp,n);
    int take=0;
    if(w>=weight[idx]){
        take=profit[idx]+get_profit(idx,w-weight[idx],profit,weight,dp,n);
    }
    return dp[idx][w]=max(take,not_take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int> (w+1,-1));
    int idx=0;
    
    return get_profit(idx,w,profit,weight,dp,n);
}


//tabulation
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // base case: dp[n][*] = 0 (already by initialization)

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int w = 0; w <= W; w++) {
            int not_take = dp[idx + 1][w];
            int take = 0;
            if (w >= weight[idx]) {
                take = profit[idx] + dp[idx][w - weight[idx]];
            }
            dp[idx][w] = max(take, not_take);
        }
    }

    return dp[0][W];
}
