#include <bits/stdc++.h> 
int get_oper(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
    if(i==j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int mini=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int steps=get_oper(i,k,arr,dp)+get_oper(k+1,j,arr,dp)+arr[i-1]*arr[k]*arr[j];
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    int i=1;
    int j=N-1;
    vector<vector<int>> dp(N,vector<int> (N,-1));
    return get_oper(i,j,arr,dp);
}


//tabulation
#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N,vector<int> (N,0));
    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<=N-1;j++){ //j should be always greater than i.
             int mini=INT_MAX;
             for(int k=i;k<=j-1;k++){
                 int steps=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                 mini=min(mini,steps);
             }
             dp[i][j]=mini;
        }
    }
    return dp[1][N-1];
}