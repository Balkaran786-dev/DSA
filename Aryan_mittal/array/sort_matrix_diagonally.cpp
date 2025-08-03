class Solution {
    public:
        vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
            int n=mat.size();
            int m=mat[0].size();
            unordered_map<int,priority_queue<int,vector<int>,greater<int>> > mp;  // diff of indices - corresponding values at those indices
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    mp[j-i].push(mat[i][j]);
                }
            }
            
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int diff=j-i;
                    mat[i][j]=mp[diff].top();
                    mp[diff].pop();
                }
            }
            return mat;
        }
    };