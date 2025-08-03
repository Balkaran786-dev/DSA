//memo  o(n*m) time  o(n*m)+o(n+m) space..
class Solution {
    public:
        int get_paths(int i,int j,int m,int n,vector<vector<int>> &dp){
            if(i==m-1 || j==n-1) return 1;
    
            if(dp[i][j]!=-1) return dp[i][j];
    
            int paths=0;
            if(i+1<m) paths+=get_paths(i+1,j,m,n,dp);
            if(j+1<n) paths+=get_paths(i,j+1,m,n,dp);
            return dp[i][j]=paths;
        }
        int uniquePaths(int m, int n) {
            int i=0,j=0;  // i iterate on rows, j on columns
            vector<vector<int>> dp(m,vector<int> (n,-1));
            return get_paths(i,j,m,n,dp);
        }
    };


//tabulation  o(n*m) time  o(n*m) space..
class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m,vector<int> (n));
            for(int j=0;j<=n-1;j++){
                dp[m-1][j]=1;
            }
            for(int i=0;i<=m-1;i++){
                dp[i][n-1]=1;
            }
            for(int i=m-2;i>=0;i--){
                for(int j=n-2;j>=0;j--){
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
                }
            }
            return dp[0][0];
        }
    };



//space optimised..  o(n*m) time  o(n) space..
class Solution {
    public:
        int uniquePaths(int m, int n) {
            if(n==1 || m==1) return 1;
            vector<int> prev(n,1);
            for(int i=m-2;i>=0;i--){
                vector<int> temp(n-1);
                for(int j=n-2;j>=0;j--){
                    if(j==n-2) temp[j]=1+prev[j];
                    else temp[j]=temp[j+1]+prev[j];
                }
                prev=temp;
            }
            return prev[0];
        }
    };




// a bit simpler to write.

    #include <bits/stdc++.h> 
    int uniquePaths(int m, int n) {
        // Write your code here.
                vector<int> prev(n);
                for(int i=m-1;i>=0;i--){
                    vector<int> temp(n);
                    for(int j=n-1;j>=0;j--){
                        if(i==m-1 && j==n-1)temp[j]=1;
                        else{
                            int down=0,right=0;
                            if(i<m-1)down+=prev[j];
                            if(j<n-1)right+=temp[j+1];
                            temp[j]=right+down;
                        }   
                    }
                    prev=temp;
                }
                return prev[0];
    }