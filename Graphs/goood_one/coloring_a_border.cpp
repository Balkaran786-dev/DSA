class Solution {
public:

    vector<vector<int>> internal;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}}; //for 4 possible directions.
    void dfs(vector<vector<int>>& grid, int row, int col, int new_color,int original_color){
        grid[row][col]=-new_color;
        for(int i=0;i<4;i++){
            int new_Row=row+dir[i][0];
            int new_Col=col+dir[i][1];
            if(new_Row>=0 && new_Col>=0 && new_Row<grid.size() && new_Col<grid[0].size() && grid[new_Row][new_Col]==original_color){
                dfs(grid,new_Row,new_Col,new_color,original_color);
            }
        }
        if(row!=0 && col!=0 && row!=grid.size()-1 && col!=grid[0].size()-1 && grid[row+1][col]==-new_color && grid[row-1][col]==-new_color && grid[row][col+1]==-new_color && grid[row][col-1]==-new_color){
                internal.push_back({row,col});  //here i can't change it to original color that would affect our rest of the cases
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int original_color=grid[row][col];
        dfs(grid,row,col,color,original_color);
        
        for(int i=0;i<internal.size();i++){
              int r=internal[i][0];
              int c=internal[i][1];
              grid[r][c]=original_color;
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==-color){
                    grid[i][j]*=-1;
                }
            }
        }
        return grid;
    }
};


/*
start from the square whose column and row is given,then in dfs function 
first check if any of its neighbour is outside the grid,push that row and column in a vector or
if any of its neighbour is of different color except -original color(that was also a original color at some point of time),then push that row and column in a vector

change this node to -original color or you can use set
now move to its all neighbours jo ki original color ke brabar ho 

after exploring all posibilities of its neighbours

change the curr node to original color.

now ,jiss vector mein sqaures store kiye the,change them to new_color.
*/