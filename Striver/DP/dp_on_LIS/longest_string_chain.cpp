class Solution {
    public:
        static bool cmp(const std::string &a, const std::string &b) {
        return a.length() < b.length();  // Sort by increasing length
        }
        bool Is_predecessor(string &s1,string &s2){
            int n1=s1.size();
            int n2=s2.size();
            if(n1+1!=n2) return false;
    
            int i=0,j=0;
            int unequal=0;
            while(i<n1 && j<n2){
                if(s1[i]==s2[j]){
                    i++;
                    j++;
                }
                else{
                    j++;
                    unequal++;
                }
            }
            return unequal<=1;
        }
        int get_LSC(int idx,int prev_idx,vector<string>& words,int n,vector<vector<int>> &dp){
            if(idx==n) return 0;
            if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
    
            int maxi=0;
            maxi=max(maxi,0+get_LSC(idx+1,prev_idx,words,n,dp));
            if(prev_idx==-1 || Is_predecessor(words[prev_idx],words[idx])){
                maxi=max(maxi,1+get_LSC(idx+1,idx,words,n,dp));
            }
            return dp[idx][prev_idx+1]=maxi;
        }
        int longestStrChain(vector<string>& words) {
            sort(words.begin(),words.end(),cmp);
            int n=words.size();
            for(int i=0;i<n;i++){
                cout<<words[i]<<" ";
            }
            vector<vector<int>> dp(n,vector<int> (n+1,-1));
            int idx=0;
            int prev_idx=-1;
            return get_LSC(idx,prev_idx,words,n,dp);
        }
    };