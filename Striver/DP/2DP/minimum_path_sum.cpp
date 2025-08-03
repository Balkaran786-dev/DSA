class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            vector<int> prev(n);
            for(int i=m-1;i>=0;i--){
                vector<int> temp(n);
                for(int j=n-1;j>=0;j--){
                    if(i==m-1 && j==n-1) temp[j]=grid[i][j];
                    else{
                        int right=INT_MAX,down=INT_MAX;
                        if(i<m-1) down=prev[j];
                        if(j<n-1) right=temp[j+1];
                        temp[j]=grid[i][j]+min(down,right);
                    }
                }
                prev=temp;
            }
            return prev[0];
        }
};