#define pp pair<int,int>
class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(queue<pair<int,int>> &qu,vector<vector<int>>& isWater,int m,int n){
        int ht=1;
        while(!qu.empty()){
            int sz=qu.size();
            while(sz--){
              pp p1=qu.front();
              qu.pop();
              int row=p1.first;
              int col=p1.second;
              for(int d=0;d<4;d++){
                int new_row=dir[d][0]+row;
                int new_col=dir[d][1]+col;
                if(new_row>=0 && new_col>=0 && new_row<m && new_col<n && isWater[new_row][new_col]==-1){
                    qu.push({new_row,new_col});
                    isWater[new_row][new_col]=ht;
                }
              }
            }
            ht++;
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        //put the indices of all water cell in queue,
        // also you would have made a new Matrix, in that put all water cell 0
        // abb jab bhi kisi aur cell ko visit kroge , update its correspoding height in this matrix
        int m=isWater.size();
        int n=isWater[0].size();
        
        queue<pp> qu;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    isWater[i][j]=0;
                    qu.push({i,j});
                }
                else isWater[i][j]=-1;
            }
        }
        bfs(qu,isWater,m,n);
        return isWater;
    }
};