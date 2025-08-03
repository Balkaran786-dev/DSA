
class Solution {
public:
    // the function returns the score difference (Alex − Bob), but you cannot ignore Bob’s moves — you must simulate his optimal play.
    // when its alex turn,ahe adds up to overall diff and expects to maximise it
    // when its bob turn, he subtracts from the overall diff and expects to minimise it.
    // this has been done so that both can play optimally..
    int result(int i,int j,vector<int>& piles,int turn,vector<vector<int>> &dp){
        if(i==j){
            if(turn==0) return -piles[i];
            return piles[i];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans;
        if(turn==1){
            ans=max(piles[i]+result(i+1,j,piles,0,dp),piles[j]+result(i,j-1,piles,0,dp));
        }
        else ans=min(-1*piles[i]+result(i+1,j,piles,1,dp),-1*piles[j]+result(i,j-1,piles,1,dp));
        return dp[i][j]=ans;
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int i=0,j=n-1;
        int turn=1; //1->alice turn 0->Bob turn
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return result(i,j,piles,turn,dp)>0;
    }
};