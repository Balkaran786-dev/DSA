class Solution {
    public:
        bool solve(int i,string s,int j,vector<vector<int>> &dp){
            if(i>=j) return true;
            if(dp[i][j]!=-1) return dp[i][j];
    
            if(s[i]==s[j]) return dp[i][j]=solve(i+1,s,j-1,dp);
            return dp[i][j]=false;
        }
        string longestPalindrome(string s) {
            int n=s.size();
            vector<vector<int>> dp(n,vector<int> (n,-1));
            int start=-1;
            int max_len=INT_MIN;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(j-i+1>max_len && solve(i,s,j,dp)){
                        start=i;
                        max_len=j-i+1;
                    }
                }
            }
    
            return s.substr(start,max_len);
        }
    };

    class Solution {
        public:
            int solve(int i,string s,int j,int n){
                int ans=(i+1==j?0:1);
                while(i>=0 && j<n && s[i]==s[j]){
                      ans+=2;
                      i--;
                      j++;
                }
                return ans;
            }
        
            string longestPalindrome(string s) {
                int n=s.size();
                // expand from the middle..
                int max_len=0;
                int start=-1;
                for(int i=0;i<n;i++){
                    int odd=solve(i-1,s,i+1,n);
                    int even=solve(i,s,i+1,n);
                    int maxi=max(odd,even);
                    if(max_len<maxi){
                        if(maxi%2==0){
                            start=i-((maxi/2)-1);
                        }
                        else{
                            start=i-(maxi/2);
                        }
                        max_len=maxi;
                    }
                }
        
                return s.substr(start,max_len);
            }
        };