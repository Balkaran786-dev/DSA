#include <bits/stdc++.h> 
int MOD=1e9+7;
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    
    int target=0;
	for(int i=0;i<n;i++){
		target+=arr[i];
	}

    vector<vector<int>> dp(n,vector<int> (target+1,-1));
    
    for(int i=0;i<=target;i++){
        if(i==0 && arr[n-1]==0) dp[n-1][0]=2;
        else if(i==0) dp[n-1][0]=1;

        else dp[n-1][i]=(arr[n-1]==i? 1 : 0);
    }

    for(int i=n-2;i>=0;i--){
        for(int j=target;j>=0;j--){
            int not_take=(dp[i+1][j])%MOD;
            int take=0;
            if(j>=arr[i]){
                take=(dp[i+1][j-arr[i]])%MOD;
            }
            dp[i][j]=(not_take+take)%MOD;
        }
    }

    int cnt=0;
    for(int i=0;i<target+1;i++){
        if(dp[0][i]!=-1 && i>=(target-i) && (2*i-target)==d){ //jo -1 nhi honge, vohi target hum achieve kr skte hain
                                                              // plus i hume actually jo first subset ke ele ka sum bta rha hai, that should be greater than second subset ke ele ka sum,
                                                              // second subset ke ele ka sum = total_sum - i , and last mein ->  (i-(target-i))==d
             cnt=(cnt+dp[0][i])%MOD;
        }
    }
    return cnt;
}


