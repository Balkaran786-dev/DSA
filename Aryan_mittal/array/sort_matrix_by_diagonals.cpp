class Solution {
    public:
        vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
            unordered_map<int,priority_queue<int>> mp1; // to form max_heap for lower half and main diagonal
            unordered_map<int,priority_queue<int,vector<int>,greater<int>> > mp2;  // to form min_heap for upper half
            
            int n=grid.size();
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    int diff=j-i;
                    if(j>i){
                       mp2[diff].push(grid[i][j]);
                    }
                    else{
                        mp1[diff].push(grid[i][j]);
                    }
                }
            }
    
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    int diff=j-i;
                    if(j>i){
                       grid[i][j]=mp2[diff].top();
                       mp2[diff].pop();
                    }
                    else{
                       grid[i][j]=mp1[diff].top();
                       mp1[diff].pop();
                    }
                }
            }
            return grid;
        }
    };