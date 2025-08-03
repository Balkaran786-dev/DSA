class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dirt={{0,1},{0,-1},{1,0},{-1,0}};
        int dis[n][m];
        for(int i=0;i<n;i++){  //sabhi nodes ka initilly source se infinte dist consider kiya
            for(int j=0;j<m;j++){
                dis[i][j]=1e9;
            }
        }
        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        dis[0][0]=0;
        int dir;
        int nx,ny;
        while(!dq.empty()){
            auto ele=dq.front();
            dq.pop_front();
            int x=ele.first;
            int y=ele.second;
            dir=grid[x][y];
            
            for(int d=0;d<4;d++){
                nx=x+dirt[d][0];
                ny=y+dirt[d][1];
                int edge_wt=1;

                if(d+1==dir){
                   edge_wt=0;
                }
                
                if(nx<n && ny<m && nx>=0 && ny>=0 ){
                   //next cell lies in the grid
                   if(dis[nx][ny]>dis[x][y]+edge_wt){
                    dis[nx][ny]=dis[x][y]+edge_wt;
                    if(edge_wt==1){
                        dq.push_back({nx,ny});
                    }
                    else{
                        dq.push_front({nx,ny});
                    }
                   }
                }
            }
        }
        return dis[n-1][m-1];
    }
};