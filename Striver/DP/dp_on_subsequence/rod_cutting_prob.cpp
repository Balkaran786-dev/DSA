int get_profit(int idx,int size,vector<int> &price,vector<vector<int>> &dp,int n){
	if(size==0) return 0;
    if(idx==n-1){
        if(size==idx+1){
            return price[idx];
        }
        return 0;
    }

    if(dp[idx][size]!=-1) return dp[idx][size];

    int not_take=get_profit(idx+1,size,price,dp,n);
    int take=0;
    if(size>=idx+1){
        take=price[idx]+get_profit(idx,size-(idx+1),price,dp,n);
    }

    return dp[idx][size]=max(take,not_take);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n,vector<int> (n+1,-1));
    int idx=0;
    
    return get_profit(0,n,price,dp,n);
}
