class Solution {
    public:
        int get_min_oper(int idx1,int idx2,int n1,int n2,string &word1,string &word2,vector<vector<int>> &dp){
            if(idx1>=n1 && idx2>=n2) return 0;
            if(idx1>=n1){
                return n2-idx2;
            }
            if(idx2>=n2){
                return n1-idx1;
            }
    
            if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
            if(word1[idx1]==word2[idx2]){
                return dp[idx1][idx2]=get_min_oper(idx1+1,idx2+1,n1,n2,word1,word2,dp);
            }
    
            return dp[idx1][idx2]=1+min(get_min_oper(idx1+1,idx2+1,n1,n2,word1,word2,dp),min(get_min_oper(idx1+1,idx2,n1,n2,word1,word2,dp),get_min_oper(idx1,idx2+1,n1,n2,word1,word2,dp)));
        }
        int minDistance(string word1, string word2) {
            int n1=word1.size();
            int n2=word2.size();
            vector<vector<int>> dp(n1,vector<int> (n2,-1));
            int idx1=0,idx2=0;
            return get_min_oper(idx1,idx2,n1,n2,word1,word2,dp);
        }
    };