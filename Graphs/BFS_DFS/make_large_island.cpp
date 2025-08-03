class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int bfs(int mark,vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int ele=1;
        queue<pair<int,int>> qu;
        qu.push({i,j});
        grid[i][j]=mark;
        while(!qu.empty()){
            pair<int,int> pp=qu.front();
            qu.pop();
            int x=pp.first;
            int y=pp.second;
            for(int d=0;d<4;d++){
                int row=x+dir[d][0];
                int col=y+dir[d][1];
                if(row<0 || col<0 || row>=n || col>=n || grid[row][col]!=1) continue;
                else{
                   ele++;
                   qu.push({row,col});
                   grid[row][col]=mark;
                }
            }
        }
        return ele;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int mark=2;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   int sz = bfs(mark,grid,i,j);
                   mp[mark] = sz;
                   mark++;
                }
            }
        }

        int area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int connected=1;
                    unordered_set<int> st;
                    for(int d=0;d<4;d++){
                       int row=i+dir[d][0];
                       int col=j+dir[d][1];
                       if(row<0 || col<0 || row>=n || col>=n || grid[row][col]==0 || st.count(grid[row][col])) continue;
                       connected+=mp[grid[row][col]];
                       st.insert(grid[row][col]);
                    }
                    area=max(area,connected);
                }
            }
            
        }
        if(area==0) return mp[2];
        return area;
    }
};