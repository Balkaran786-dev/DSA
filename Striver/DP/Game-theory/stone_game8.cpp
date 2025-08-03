//naman's code..
//if you r at ith index, either you break there and incremnet the index, or let your opponent break there.
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int f(int i,int turn,vector<int>& pref){
        if(i==n-1){
            if(turn==0)return pref[i];
            return -pref[i];
        };
        if(dp[i][turn]!=-1)return dp[i][turn];
        if(turn==0){
            return dp[i][turn]=max(pref[i]+f(i+1,1,pref),f(i+1,turn,pref));
        }
        else{
            return dp[i][turn]=min(-pref[i]+f(i+1,0,pref),f(i+1,turn,pref));
        }
    }
    int stoneGameVIII(vector<int>& stones) {
        n=stones.size();
        dp.resize(n,vector<int>(2,-1));
        vector<int> pref(n,0);
        pref[0]=stones[0];
        for(int i=1;i<n;i++){
            pref[i]=stones[i]+pref[i-1];
        }
        return f(1,0,pref);
    }
};