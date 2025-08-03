class Solution {
public:
    unordered_set<string> st;
    bool breakable(string &s,int idx,int n,vector<int> &dp){
        if(idx==n) return true;

        if(st.find(s.substr(idx))!=st.end()){
            return true;
        }

        if(dp[idx]!=-1) return dp[idx];

        for(int l=1;l<=n;l++){   //hum aage badhenge hi tab, jab jo oechle hain word, voh exist krte ho....
        //jis bhi index par hai hum, vahan se lekar kisi bhi length tak ki substring consider kr skte hain.....
            string temp=s.substr(idx,l);
            if(st.find(temp)!=st.end() && breakable(s,idx+l,n,dp)){
                return dp[idx]=true;
            }
        }

        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=wordDict.size();
        for(int i=0;i<n;i++){
            st.insert(wordDict[i]);
        }
        
        int sz=s.size();
        vector<int> dp(sz,-1);
        int idx=0;
        return breakable(s,idx,sz,dp);
    }
};