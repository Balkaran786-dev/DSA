//similar to how we did in bfs,bss
//we need to call dfs from all the sources.
//for loop we used for adding sources in the queue,
//we are going to use that to call all dfs for all those cells.
// #include<bits/stdc++.h>
// using namespace std;
// int row;
// int col;
// vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
// vector<vector<int>> heights;
// vector<vector<bool>> bfs(queue<pair<int,int>> &qu){
//          vector<vector<bool>> ans(row,vector<bool> (col,false));
//          while(!qu.empty()){
//             auto ele=qu.front();
//             qu.pop();
//             int r=ele.first;
//             int c=ele.second;
//             ans[r][c]=true;
//             for(int i=0;i<4;i++){
//                 int new_Row=r+dir[i][0];
//                 int new_Col=c+dir[i][1];
//                 if(new_Row<0 || new_Col<0 || new_Row>=row || new_Col>=col) continue;  //you r going out of grid
//                 if(ans[new_Row][new_Col]==true) continue;  //you have already visted the cell
//                 if(heights[new_Row][new_Col]<heights[r][c]) continue;
//                 qu.push(make_pair(new_Row,new_Col));
//             }
//          }
// }
// vector<vector<int>> pacific_atlantic_cells(){
//     vector<vector<int>> ans;
//     queue<pair<int,int>> pacific;
//     queue<pair<int,int>> atlantic;

//     for(int i=0;i<row;i++){
//         pacific.push(make_pair(i,0));
//         atlantic.push(make_pair(i,col-1));
//     }
//     atlantic.push(make_pair(row-1,0));
//     for(int j=1;j<col;j++){
//         pacific.push(make_pair(0,j));
//         if(j!=col-1){
//             atlantic.push(make_pair(row-1,j));
//         }
//     }
//     vector<vector<bool>> pacific_bfs= bfs(pacific);
//     vector<vector<bool>> atlantic_bfs= bfs(atlantic);
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             if(pacific_bfs[i][j]==true && atlantic_bfs[i][j]==true){
//                 ans.push_back({i,j});
//             }
//         }
//     }
//     return ans;
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     row=n;
//     col=m;
//     heights.resize(n);
//     for(int i=0;i<n;i++){
//         heights[i].resize(m);
//         for(int j=0;j<m;j++){
//             cin>>heights[i][j];
//         }
//     }
//     vector<vector<int>> result=pacific_atlantic_cells();
//     for(int i=0;i<result.size();i++){
//         for(int j=0;j<2;j++){
//             cout<<result[i][j]<<",";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};// i,j -> i+1,j -> i-1,j -> i,j+1 -> i,j-1;
    vector<vector<int>> h;
    int rows;
    int cols;
    vector<vector<bool>> bfs(queue<pair<int,int>> &qu){
        vector<vector<bool>> visited(rows,vector<bool> (cols,false));
        while(!qu.empty()){
            auto ele=qu.front();
            qu.pop();
            int i=ele.first;
            int j=ele.second;
            visited[i][j]=true;
            for(int d=0;d<4;d++){
                int row =i+dir[d][0];
                int col =j+dir[d][1];
                if(row<0 || col<0 || row>=rows || col>=cols) continue; //means we got out of the grid
                if(visited[row][col]) continue;  //means that cell is already selected,no need to go again
                if(h[row][col]<h[i][j]) continue; //means the neighbour size is less than the parentnode,so,we won't be able to push water to neigh;
                qu.push({row,col});
            }
        }
        return visited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows=heights.size();
        cols=heights[0].size();
        h=heights;
        queue<pair<int,int>> pacific;
        queue<pair<int,int>> atlantic;


        //step of multisource bfs
        for(int i=0;i<rows;i++){
            pacific.push({i,0});
            atlantic.push({i,cols-1});
        }
        for(int j=1;j<cols;j++){  
            pacific.push({0,j});
        }
        for(int k=0;k<cols-1;k++){
            atlantic.push({rows-1,k});
        }
        
        vector<vector<bool>> bfs_pacific=bfs(pacific);
        vector<vector<bool>> bfs_atlantic=bfs(atlantic);

        vector<vector<int>> result;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(bfs_pacific[i][j] && bfs_atlantic[i][j]){
                      result.push_back({i,j});
                }
            }
        }
        return result;
    }
};