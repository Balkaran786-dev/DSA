class Solution {
    public:
        int get_oper(int i,int j,int n,string &s,vector<vector<int>> &dp){
            if(i>=j) return 0;
            
            if(dp[i][j]!=-1) return dp[i][j];
            
            int ans=INT_MAX;
            if(s[i]==s[j]) ans=0+get_oper(i+1,j-1,n,s,dp);
            else{
                int temp=INT_MAX;
                temp=min(temp,1+get_oper(i+1,j,n,s,dp));
                temp=min(temp,1+get_oper(i,j-1,n,s,dp));
                ans=temp;
            }
            return dp[i][j]=ans;
        }
        int minInsertions(string s) {
            int n=s.size();
            vector<vector<int>> dp(n,vector<int> (n,-1));
            int idx1=0,idx2=n-1;
            return get_oper(idx1,idx2,n,s,dp);
        }
    };