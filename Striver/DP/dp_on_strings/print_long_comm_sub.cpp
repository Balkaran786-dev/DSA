#include<bits/stdc++.h>
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
	vector<vector<pair<int,char>>> dp(n+1,vector<pair<int,char>> (m+1,{0,'s'}));
    for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]={1+dp[i-1][j-1].first,'d'}; //diagonal
			}
			else if(dp[i][j-1].first>=dp[i-1][j].first){
				dp[i][j]={dp[i][j-1].first,'l'}; //left
			}
			else if(dp[i][j-1].first<dp[i-1][j].first){
				dp[i][j]={dp[i-1][j].first,'u'};  //upper
			}
		}
	}

    string str(dp[n][m].first,' ');

	int idx=dp[n][m].first-1;
	int i=n,j=m;
	while(i!=0 && j!=0){
        if(dp[i][j].second=='d'){
			str[idx--]=s1[i-1];
			i-=1;
			j-=1;
		}
		else if(dp[i][j].second=='u'){
			i-=1;
		}
		else{
			j-=1;
		}
	}

	return str;
}