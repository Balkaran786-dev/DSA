//tabulation
#include<bits/stdc++.h>
int get_cost(int i,int last,vector<vector<int>> &cost,vector<vector<int>> &dp){
	if(i==0){
		int mini=INT_MAX;
		for(int j=0;j<=2;j++){
			if(last!=j){
				mini=min(mini,cost[0][j]);
			}
		}
		return mini;
	}

	if(dp[i][last]!=-1) return dp[i][last];
    
	int mini=INT_MAX;
	for(int j=0;j<=2;j++){
		if(last!=j){
          mini=min(mini,cost[i][j]+get_cost(i-1,j,cost,dp));
		}
	}

	return dp[i][last]=mini;
}
int minCost(vector<vector<int>> &cost)
{
	//	Write your code here.
	int n=cost.size();
	int last=3;
    vector<vector<int>> dp(n,vector<int> (4,-1));
	return get_cost(n-1,last,cost,dp);
}


//bottom up
#include<bits/stdc++.h>

int minCost(vector<vector<int>> &cost)
{
	int n=cost.size();
	vector<int> prev(4);
    prev[0]=min(cost[0][1],cost[0][2]);
    prev[1]=min(cost[0][0],cost[0][2]);
    prev[2]=min(cost[0][0],cost[0][1]);
    prev[3]=min(cost[0][0],min(cost[0][1],cost[0][2]));

    for(int day=1;day<=n-1;day++){
        vector<int> temp(4);
        for(int last=0;last<=3;last++){

            temp[last]=0;
            int mini=INT_MAX;
            for(int task=0;task<=2;task++){
                if(last!=task){
                   mini=min(mini,cost[day][task]+prev[task]);
                }
            }
            temp[last]=mini;
        }

        prev=temp;
    }
    return prev[3];
}