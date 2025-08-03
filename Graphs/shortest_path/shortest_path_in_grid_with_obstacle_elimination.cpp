//hum agr kisi node pe pehle visit nhi kiye toh usko visit krenge
//agr phele visit kre hain but jab abb hum visit kr rhe hain, remoed walls pechle visite se kam hai, toh isko bhi consider krenge.

//similar to k flights question ,
//usme weights alg the, isiliye and last mein after loop miliga
//isme weights 1 hi hai, toh jaise hi last cell tak pahunchenge, return kr denge...

class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> removed(m, vector<int>(n, 0)),
            visited(m, vector<int>(n, -1));

        queue<pair<int, pair<int,int>>> qu;
        if(grid[0][0]==1) qu.push({1,{0,0}});
        else qu.push({0,{0,0}});
        int level = 0;
        while (!qu.empty()) {
            int sz = qu.size();
            while (sz--) {
                auto curr = qu.front();
                qu.pop();
                int rem = curr.first, x = curr.second.first , y=curr.second.second;

                if (x == m - 1 && y == n - 1)
                    return level;

                for (int d = 0; d < 4; d++) {
                    int n_x = x + dir[d][0];
                    int n_y = y + dir[d][1];
                    if (n_x < 0 || n_y < 0 || n_x >= m ||
                        n_y >= n)
                        continue;
                    
                    if(visited[n_x][n_y]==-1){
                        if(grid[n_x][n_y]==1){
                            if(rem+1<=k){
                               visited[n_x][n_y]=1;
                               qu.push({rem+1,{n_x,n_y}});
                               removed[n_x][n_y]=rem+1;
                            } 
                        }
                        else{
                            visited[n_x][n_y]=1;
                            qu.push({rem,{n_x,n_y}});
                            removed[n_x][n_y]=rem;
                        }
                    }
                    else if(removed[n_x][n_y]>rem){
                        if(grid[n_x][n_y]==1){
                            if(rem+1<=k){
                               qu.push({rem+1,{n_x,n_y}});
                               removed[n_x][n_y]=rem+1;
                            } 
                        }
                        else{
                            qu.push({rem,{n_x,n_y}});
                            removed[n_x][n_y]=rem;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};