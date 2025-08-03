//memo..
class Solution {
    public:
        int get_cherry(vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>> &dp,int n,int m){
            if(i==n-1){
                if(j1==j2) return grid[i][j1];
                return grid[i][j1]+grid[i][j2];
            }
    
            if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
            
            int maxi=INT_MIN;
            for(int dj1=-1 ;dj1<=1 ;dj1++){
                int col1=dj1+j1;
                for(int dj2=-1 ;dj2<=1 ;dj2++){
                    int col2=dj2+j2;
                    if(col1 < 0 || col1>=m || col2<0 || col2>=m) continue;
    
                    if(j1==j2) maxi=max(maxi,grid[i][j1]+get_cherry(grid,i+1,col1,col2,dp,n,m));
                    else maxi=max(maxi,grid[i][j1]+grid[i][j2]+get_cherry(grid,i+1,col1,col2,dp,n,m));
                }
            } 
    
            return dp[i][j1][j2]=maxi;       
        }
        int cherryPickup(vector<vector<int>>& grid) {
            // three states change horhi hai,
            // row1 and row2 dono ko row hi le skte hai ek,(actually dono ek sath hi move ho rhe hain isiliye row same rhegi)
            // col1- robot1 ka
            // col2- robot2 ka
    
            int n=grid.size();
            int m=grid[0].size();
    
            vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));
            int i=0,j1=0,j2=m-1;
            return get_cherry(grid,i,j1,j2,dp,n,m);
        }
    };

    
//tabulation..
// space optimsation
// pehle bina space optimisation vali krna..
class Solution {
    public:
        int cherryPickup(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> prev(m, vector<int>(m));
            for (int j1 = 0; j1 < m; j1++) { // base case.
                for (int j2 = 0; j2 < m; j2++) {
                    if (j1 == j2)
                        prev[j1][j2] = grid[n - 1][j1];
                    else
                        prev[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
                }
            }
    
            for (int row = n - 2; row >= 0; row--) {
                vector<vector<int>> temp(m, vector<int>(m));
                for (int j1 = 0; j1 < m; j1++) {
                    for (int j2 = 0; j2 < m; j2++) {
    
                        int maxi = INT_MIN;
    
                        for (int dj1 = -1; dj1 <= 1; dj1++) {
                            int col1 = dj1 + j1;
                            for (int dj2 = -1; dj2 <= 1; dj2++) {
                                int col2 = dj2 + j2;
                                if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) continue;
                                if (j1 == j2) maxi = max(maxi, grid[row][j1] + prev[col1][col2]);
                                else maxi = max(maxi, grid[row][j1] + grid[row][j2] + prev[col1][col2]);
                            }
                        }
                        temp[j1][j2]=maxi;
                    }
                }
                prev=temp;
            }
            return prev[0][m-1];
        }
    };