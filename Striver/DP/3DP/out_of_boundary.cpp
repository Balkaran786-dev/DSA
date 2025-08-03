class Solution {
public:
    int MOD=1e9+7;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int find(int i,int j,int m,int n,int moves,vector<vector<vector<int>>> &dp){
        if(i<0 || j<0 || i>=m || j>=n) return 1;
        if(moves==0) return 0;

        if(dp[i][j][moves]!=-1) return dp[i][j][moves];

        int ans=0;
        for(int d=0;d<4;d++){
            int row=i+dir[d][0];
            int col=j+dir[d][1];
            ans=(ans+(find(row,col,m,n,moves-1,dp))%MOD)%MOD;
        }
        return dp[i][j][moves]=ans%MOD;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (maxMove+1,-1)));

        return find(startRow,startColumn,m,n,maxMove,dp);
    }
};