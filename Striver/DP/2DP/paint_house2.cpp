#include <bits/stdc++.h> 
int get_cost(int i,int last,vector<vector<int>> &cost,vector<vector<int>> &dp,int k){
	if(i==0){
		int mini=INT_MAX;
		for(int j=0;j<k;j++){
			if(last!=j){
				mini=min(mini,cost[0][j]);
			}
		}
		return mini;
	}

	if(dp[i][last]!=-1) return dp[i][last];
    
	int mini=INT_MAX;
	for(int j=0;j<k;j++){
		if(last!=j){
          mini=min(mini,cost[i][j]+get_cost(i-1,j,cost,dp,k));
		}
	}

	return dp[i][last]=mini;
}
int paintCost(int n, int k, vector<vector<int>> &cost)
{
   // Write your code here
	int last=k;
   vector<vector<int>> dp(n,vector<int> (k+1,-1));
	return get_cost(n-1,last,cost,dp,k);
}
