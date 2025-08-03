class Solution {
    public:
        bool helper(int i,int j,string &s,string &p,int n1,int n2,vector<vector<int>> &dp){
            if(i<0 && j<0) return true;
            else if(i<0){
               if(p[j]=='*'){
                    while(j>=0){
                        while(p[j]=='*') j--;
                        j--;
                        if(j>=0 && p[j]!='*') return false; 
                    }
                    return true;
               }
               else return false;
            }
            else if(j<0) return false;
    
            if(dp[i][j]!=-1) return dp[i][j];
    
            bool ans=false;
            if(p[j]==s[i] || p[j]=='.') ans=helper(i-1,j-1,s,p,n1,n2,dp);
            else if(p[j]=='*'){
                ans=helper(i,j-2,s,p,n1,n2,dp);
                bool temp=false;
                for(int idx=i;idx>=0;idx--){
                    if(p[j-1]==s[idx] || p[j-1]=='.'){
                        temp= temp || helper(idx-1,j-2,s,p,n1,n2,dp);
                    }
                    else break;
                }
                ans = ans ||  temp;
            }
            else if(p[j]!=s[i]) ans=false;
            return dp[i][j]=ans;
        }
        bool isMatch(string s, string p) {
            int n1=s.size();
            int n2=p.size();
            int i=n1-1,j=n2-1;
            vector<vector<int>> dp(n1,vector<int> (n2,-1));
            return helper(i,j,s,p,n1,n2,dp);
        }
    };