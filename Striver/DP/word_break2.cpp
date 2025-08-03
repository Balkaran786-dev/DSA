class Solution {
public:
    unordered_set<string> st;
    vector<string> helper(int i,int n,string &s,vector<vector<string>> &dp){
        if(i>=n) return {""};

        if (!dp[i].empty()) return dp[i];

        vector<string> ans;
        for(int l=i;l<n;l++){
            string curr=s.substr(i,l-i+1);
            
            if(st.find(curr)!=st.end()){
                vector<string> vec=helper(l+1,n,s,dp);
                for(auto ele:vec){
                if(ele.empty()){
                    ans.push_back(curr);
                }
                else{
                    ans.push_back(curr+" "+ele);
                }
            }
            }
            
        }
        return dp[i]=ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        int sz=wordDict.size();
        for(int i=0;i<sz;i++){
            st.insert(wordDict[i]);
        }

        vector<vector<string>> dp(n);
        int i=0;
        return helper(i,n,s,dp);
    }
};