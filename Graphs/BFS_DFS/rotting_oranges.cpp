/*
why we are not using dfs here? because usme hum ek neighbour pe jakar uske aage exploration
karne lag jayega,lekin yahan ek rotten orange eksath apne sare adjacent oranges ko rote
kar rha hai.By using BFS,we would be able to calculate the min time needed to make all
oranges rotten.

  $$$$ it is a question on multisource bfs $$$
we run a loop on all the cells,
if some cell contain rotten orange we add them in a queue.
if some cell contain fresh oranges,we increase the no.of fresh oranges.
In this bfs,we move from all the possible sources to their adjacent cells only if
there is a fresh source,we make it rotten and add it in the queue and decrease the no.
of fresh oranges.
after our queue gets empty,we check if the no. of fresh oranges are zero.
if yes,return total_time else return -1;
*/


class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_oranges=0;
        queue<pair<int,int>> qu;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    qu.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh_oranges++;
                }
            }
        }
        if(fresh_oranges==0) return 0;  //agr ek bhi fresh_orange nhi hai,toh yehi return krdo 0 varna voh baad mein -1 return krdega,agr koi rotten bhi nhi hoga
        int time=-1;
        while(!qu.empty()){
            int cells=qu.size();
            while(cells--){
               auto node=qu.front();
               qu.pop();
               int row=node.first;
               int col=node.second;
               for(int d=0;d<4;d++){
                   int new_row=row+dir[d][0];
                   int new_col=col+dir[d][1];
                   if(new_row<0 || new_col<0 || new_row>=grid.size() || new_col>=grid[0].size()){
                    continue;
                   }
                   if(grid[new_row][new_col]==2 || grid[new_row][new_col]==0) continue;
                   qu.push({new_row,new_col});  //matlab 1 hoga means fresh
                   grid[new_row][new_col]=2;
                   fresh_oranges--;
               }
            }
            time++;
        }

        return (fresh_oranges==0? time : -1);
    }
};