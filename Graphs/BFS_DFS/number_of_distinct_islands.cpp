
class Solution {
  public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& grid,int row,int col,int rel_row,int rel_col,vector<pair<int,int>> &vec){
        vec.push_back({rel_row-row,rel_col-col});
        grid[row][col]=2;
        for(int d=0;d<4;d++){
            int new_row=row+dir[d][0];
            int new_col=col+dir[d][1];
            if(new_row>=0 && new_col>=0 && new_row<grid.size() && new_col<grid[0].size() && grid[new_row][new_col]==1){
                dfs(grid,new_row,new_col,rel_row,rel_col,vec);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(grid,i,j,i,j,vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

