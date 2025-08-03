class Solution {
public:
    vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> qu;
        bool flag=true;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(flag && grid[i][j]==0){
                    flag=false;
                }
                if(grid[i][j]==1){
                    qu.push({i,j});
                }
            }
        }
        if(flag) return -1;
        set<pair<int,int>> st;
        while(!qu.empty()){
           int sz=qu.size();
           while(sz--){
              pair<int,int> pp=qu.front();
              qu.pop();
              int x=pp.first;
              int y=pp.second;
              for(int d=0;d<4;d++){
                int row=x+dir[d][0];
                int col=y+dir[d][1];
                if(row<0 || col<0 || row>=n || col>=n || grid[row][col]==1 || st.count({row,col})) continue;
                qu.push({row,col});
                st.insert({row,col});
              }
           }
           cnt++;
        }
        
        if(cnt==0) return -1;
        return cnt-1;
    }
};