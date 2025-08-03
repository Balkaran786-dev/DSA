// 1st solution by DSU.



//second solution by frequencyy arrays
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> row_count(n,0);
        vector<int> col_count(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }

            int total_servers=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j] && (row_count[i]>1 || col_count[j]>1)){
                        total_servers++;
                    }
                }
            }

        return total_servers;
    }
};