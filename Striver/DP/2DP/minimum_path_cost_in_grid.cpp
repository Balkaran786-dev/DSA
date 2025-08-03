class Solution {
public:
    int get_cost(int row,int col,int m,int n,vector<vector<int>>& grid, vector<vector<int>>& moveCost,vector<vector<int>> &dp){
         if(row==m-1) return grid[row][col];
         if(dp[row][col]!=-1) return dp[row][col];
         
         int mini=INT_MAX;
         for(int j=0;j<n;j++){
             mini=min(mini,grid[row][col]+moveCost[grid[row][col]][j]+get_cost(row+1,j,m,n,grid,moveCost,dp)); 
         }

         return dp[row][col]=mini;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,get_cost(0,i,m,n,grid,moveCost,dp));
        }

        return mini;
    }
};