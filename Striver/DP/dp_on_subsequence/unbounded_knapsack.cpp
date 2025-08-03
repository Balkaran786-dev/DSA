int get_profit(int idx,int w,vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp,int n){
    if(idx==n-1){
        if(w>=weight[idx]){
            int q=w/weight[idx];
            return profit[idx]*q;
        }
        return 0;
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