// memo
class Solution {
    public:
        int get_min_path(vector<vector<int>>& triangle,int row,int col,vector<vector<int>> &dp,int n){
            if(row==n-1){
                return triangle[row][col];
            }
            
            if(dp[row][col]!=-1) return dp[row][col];
            return dp[row][col]=triangle[row][col]+min(get_min_path(triangle,row+1,col,dp,n),get_min_path(triangle,row+1,col+1,dp,n));
        }
        int minimumTotal(vector<vector<int>>& triangle) {
            int n=triangle.size();
            vector<vector<int>> dp(n);
            for(int i=0;i<n;i++){
                dp[i].resize(i+1,-1);
            }
            int row=0, col=0;
            return get_min_path(triangle,row,col,dp,n);
        }
    };


    // tabulation o(n) space

    class Solution {
        public:
            int minimumTotal(vector<vector<int>>& triangle) {
                int n=triangle.size();
                vector<int> prev(n);
                for(int i=0;i<n;i++){
                    prev[i]=triangle[n-1][i];
                }
        
                for(int row=n-2;row>=0;row--){
                    vector<int> temp(n,-1);
                    for(int col=row;col>=0;col--){
                        temp[col]=triangle[row][col]+min(prev[col],prev[col+1]);
                    }
                    prev=temp;
                }
                return prev[0];
            }
        };