class Solution {
    public:
        int get_cost(int i,int j,vector<int>& cuts,vector<vector<int>> &dp){
            if(i>j) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
    
            int mini=INT_MAX;
            for(int k=i;k<=j;k++){
                int steps=get_cost(i,k-1,cuts,dp)
                + get_cost(k+1,j,cuts,dp) + cuts[j+1]-cuts[i-1];
                mini=min(mini,steps);
            }
    
            return dp[i][j]=mini;
        }
    
        int minCost(int n, vector<int>& cuts) {
            cuts.push_back(0);
            cuts.push_back(n);
            sort(cuts.begin(),cuts.end());
            int sz=cuts.size();
            int i=1;
            int j=sz-2;
            int left=0;
            int right=n;
            vector<vector<int> > dp(sz,vector<int> (sz,-1));
            return get_cost(i,j,cuts,dp);
        }
    };