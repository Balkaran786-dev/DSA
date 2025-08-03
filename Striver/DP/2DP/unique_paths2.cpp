class Solution {
    public:
        int get_paths(int i,int j,int m,int n,vector<vector<unsigned long int>> &dp,vector<vector<int>>& Grid){
                if (Grid[i][j] == 1) return 0;
                if (i == m - 1 && j == n - 1) return 1;
                if (dp[i][j] != -1) return dp[i][j];
    
                unsigned long int left=0,right=0;
                if(i+1<m && Grid[i+1][j]!=1) left+=get_paths(i+1,j,m,n,dp,Grid);
                if(j+1<n && Grid[i][j+1]!=1) right+=get_paths(i,j+1,m,n,dp,Grid);
                return dp[i][j]=(left+right);
        }
        int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
                int m=Grid.size();
                int n=Grid[0].size();
                int i=0,j=0;  // i iterate on rows, j on columns
                vector<vector<unsigned long int>> dp(m,vector<unsigned long int> (n,-1));
                return get_paths(i,j,m,n,dp,Grid); 
        }
    };