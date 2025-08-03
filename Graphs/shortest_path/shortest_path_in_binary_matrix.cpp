//we can also this question using simple BFS, as there is no weightage, only unit distance is presnt
// so after covering all nodes at the same level we can increase the distance,
// and as soon as we reach the destination we can return the distance,
// if after the while loop, we wil return -1. beacuse we have not reached the destination.
// /o(n^2) means we just traverse the matrix once. and for every node we just move to its 8 neighbours and we never traverse them back/.



class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    using pp = pair<int,pair<int,int>>;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>> distance(n, vector<int> (n,INT_MAX));
        distance[0][0]=1;
        
        priority_queue<pp,vector<pp>,greater<pp>> pq;

        pq.push({1,{0,0}});

        while(!pq.empty()){
            pp curr=pq.top();
            pq.pop();

            int dist=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;
            grid[i][j]=1;

            for(int d=0;d<8;d++){
                int row=i+dir[d][0];
                int col=j+dir[d][1];
            
                if(row<0 || col<0 || row>=n || col>=n || grid[row][col]==1) continue;
                
        
                if(distance[row][col]>dist+1){
                    
                    distance[row][col]=dist+1;
                    pq.push({dist+1,{row,col}});
                }
            }
        }
        
      
        if(distance[n-1][n-1] == INT_MAX) return -1;
        return distance[n-1][n-1];
    }
};