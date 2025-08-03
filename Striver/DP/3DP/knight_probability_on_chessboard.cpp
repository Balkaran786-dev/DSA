class Solution {
public:
    vector<vector<int>> dir={{-2,1},{-2,-1},{2,1},{2,-1},{1,-2},{1,2},{-1,2},{-1,-2}};
    double find(int i,int j,int n,int k,vector<vector<vector<double>>> &dp){
        if(i<0 || j<0 || i>=n || j>=n) return 0;
        if(k==0) return 1;

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        double ans=0;
        for(int d=0;d<8;d++){
            int new_row=i + dir[d][0];
            int new_col=j + dir[d][1];
    
            ans+=(double)find(new_row,new_col,n,k-1,dp);
        }

        return dp[i][j][k]=(double)ans/8.0;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>> (n,vector<double> (k+1,-1)));
        //summation rule of probability has been applied here..
        // agr ek kaam krne ke 3 tarike hain , so the proebability of doing that work will be
        // the sum of probabilities of these 3 work divided by 3....
        return find(row,column,n,k,dp);
    }
};