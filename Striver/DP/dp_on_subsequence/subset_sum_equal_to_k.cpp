#include <bits/stdc++.h>
bool if_exist(int idx,vector<int> &arr,int n,int target,vector<vector<int>> &dp){
    if(target==0) return true;
    if(idx==n-1) return arr[idx]==target;

    if(dp[idx][target]!=-1) return dp[idx][target]==1;

    bool not_take=if_exist(idx+1,arr,n,target,dp);
    bool take=false;
    
    if(target>=arr[idx]){
        take=if_exist(idx+1,arr,n,target-arr[idx],dp);
    }
    bool ans=take || not_take;
    if(ans==true) dp[idx][target]=1;
    else dp[idx][target]=0;
    return ans;
} 
bool subsetSumToK(int n, int target, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int> (target+1,-1));
    int idx=0;
    return if_exist(idx,arr,n,target,dp);
}


//space optimisation tabulation
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int target, vector<int> &arr) {
    // Write your code here.
    vector<bool> prev(target+1);
    for(int i=0;i<target+1;i++){
        if(i==0) prev[i]=true;
        else prev[i]=(arr[n-1]==i);
    }
    
    for(int i=n-2;i>=0;i--){
        vector<bool> temp(target+1);
        for(int j=target;j>=0;j--){
            bool not_take=prev[j];
            bool take=false;
            if(j>=arr[i]){
                take=prev[j-arr[i]];
            }
            temp[j]=take || not_take;
        }
        prev=temp;
    }
    return prev[target];
}