class Solution {
public:
    int f(int i,int j,int turn,vector<int>& stones,vector<vector<vector<int>>> &dp,vector<int> &prefix){
        if(i==j) return 0;

        if(dp[i][j][turn]!=-1) return dp[i][j][turn];
        int result;
        if(turn==1){
            result=INT_MIN;
            int sum=prefix[j-1]-(i==0? 0:prefix[i-1]);
            result=max(result,sum+f(i,j-1,0,stones,dp,prefix));
            sum=prefix[j]-prefix[i];
            result=max(result,sum+f(i+1,j,0,stones,dp,prefix));
            return dp[i][j][turn]=result;
        }
        else{
            result=INT_MAX;
            int sum=prefix[j-1]-(i==0? 0:prefix[i-1]);
            result=min(result,-sum+f(i,j-1,1,stones,dp,prefix));
            sum=prefix[j]-prefix[i];
            result=min(result,-sum+f(i+1,j,1,stones,dp,prefix));
            return dp[i][j][turn]=result;
        }
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<int> prefix(n);
        prefix[0]=stones[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stones[i];
        }

        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int> (2,-1)));
        int i=0,j=n-1,turn=1;
        return f(i,j,turn,stones,dp,prefix);
    }
};