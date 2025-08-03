class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int get_paths(int row,int col,int m,int n,vector<vector<int>>& grid,int k){
        if(row<0 || col<0 || row>=m || col>=n || grid[row][col]==-1) return 0;
        if(grid[row][col]==2){
            if(k==0)return 1;
            return 0;
        }
        grid[row][col]=-1;
        int paths=0;
        for(int d=0;d<4;d++){
            int new_row=row+dir[d][0];
            int new_col=col+dir[d][1];
            paths+=get_paths(new_row,new_col,m,n,grid,k-1);
        }
        grid[row][col]=0;
        return paths;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int non_covered=0;
        int row=0,col=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    row=i;
                    col=j;
                    non_covered++;
                }
                if(grid[i][j]==0) non_covered++;
            }
        }

        
        return get_paths(row,col,m,n,grid,non_covered);
    }
};