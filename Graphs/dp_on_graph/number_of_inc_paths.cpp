class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int MOD=1e9+7;
    int f(int i,int j,int m,int n,vector<vector<int>> &dp,vector<vector<int>>& grid){

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=1;
        for(int d=0;d<4;d++){
            int row=i+dir[d][0];
            int col=j+dir[d][1];

            if(row<0 || col<0 || row>=m || col>=n || grid[row][col]<=grid[i][j]) continue;
            ans=(ans+(f(row,col,m,n,dp,grid))%MOD)%MOD;
        }
        return dp[i][j]=ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dp(m,vector<int> (n,-1));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1){
                    ans=(ans+f(i,j,m,n,dp,grid))%MOD;
                }
                else ans=(ans + dp[i][j])%MOD;
            }
        }
        return ans;
    }
};