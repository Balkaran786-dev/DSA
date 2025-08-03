class Solution {
public:
    int find(int i,int n,int days,int maxi,vector<int>& vec,int d,vector<vector<vector<int>>> &dp){
        if(i==n){  //array khatam
            if(days==d) return 0;  //agr prper distrubution hui
            return INT_MAX;   //otherwise
        }
        if(days>=d) return INT_MAX;

        if(dp[i][maxi][days]!=-1) return dp[i][maxi][days];

        int mini=INT_MAX;
        int to_put=max(maxi,vec[i]);
        int take=find(i+1,n,days,to_put,vec,d,dp);
        mini=min(mini,take);

        int not_take=find(i+1,n,days+1,0,vec,d,dp);
        if(not_take!=INT_MAX) mini=min(mini,to_put+not_take);

        return dp[i][maxi][days]=mini;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
           maxi=max(jobDifficulty[i],maxi);
        }

        vector<vector<vector<int>>> dp(n,vector<vector<int>> (maxi+1,vector<int> (d+1,-1)));
        
        int i=0;
        int days=0;
        int ans=find(i,n,days,jobDifficulty[0],jobDifficulty,d,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};


//2d DP
// jo 0/1 knapsack ka question 3d DP mein chla jaye, try to bring for loop this way in the recursive code
// to bring it down to 2d DP.

class Solution {
public:
    int find(int i,int n,int days,vector<int>& vec,int d,vector<vector<int>> &dp){
        if(i==n){  //array khatam
            if(days==d) return 0;  //agr proper distrubution hui
            return INT_MAX;   //otherwise
        }
        if(days>=d) return INT_MAX;

        if(dp[i][days]!=-1) return dp[i][days];

        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int idx=i;idx<n;idx++){
            maxi=max(maxi,vec[idx]);
            int ans=find(idx+1,n,days+1,vec,d,dp);
            if(ans!=INT_MAX) mini=min(mini,maxi+ans);
        }

        return dp[i][days]=mini;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        vector<vector<int>> dp(n,vector<int> (d+1,-1)); 
        int i=0;
        int days=0;
        int ans=find(i,n,days,jobDifficulty,d,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};