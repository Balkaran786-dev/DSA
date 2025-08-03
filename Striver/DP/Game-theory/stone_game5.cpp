class Solution {
public:
    //isme simple yeh function return krega alex ka score,
    //alex sarri possibilities explore krega ,
    // agr dono part ka sum same hua, toh dono part explore krenge ek ek baar..
    
    int f(int i,int j,vector<int>& stoneValue,vector<vector<int>> &dp,vector<int> &prefix){
        if(i==j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int maxi=0;
        for(int k=i;k<=j-1;k++){
            int left_part=prefix[k]-(i==0?0:prefix[i-1]);
            int right_part=prefix[j]-prefix[k];
            if(left_part==right_part){
                maxi=max(maxi,right_part+f(k+1,j,stoneValue,dp,prefix));//left remove
                maxi=max(maxi,left_part+f(i,k,stoneValue,dp,prefix));  //right_remove
            }
            else if(left_part>right_part){
                maxi=max(maxi,right_part+f(k+1,j,stoneValue,dp,prefix));//left remove
            }
            else maxi=max(maxi,left_part+f(i,k,stoneValue,dp,prefix));  //right remove
        }
        return dp[i][j]=maxi;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> prefix(n);
        prefix[0]=stoneValue[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stoneValue[i];
        }
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int i=0,j=n-1;
        return f(i,j,stoneValue,dp,prefix);
    }
};