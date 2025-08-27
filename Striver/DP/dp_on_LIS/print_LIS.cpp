vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	// Write your code here
	vector<int> backtrack(n);  //to trace back the LIS
	for(int i=0;i<n;i++){
		backtrack[i]=i;  //first of all, all index will have the starting of LIS from them selves only...
	}

	vector<int> dp(n,1);
	for(int i=1;i<n;i++){
		int maxi=0;
		int idx=-1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
				if(maxi<dp[j]){
					maxi=dp[j];
					idx=j;
				}
			}
		}
		if(maxi!=0){
			dp[i]+=maxi;
			backtrack[i]=idx;
		}
	}
    
	int maxi=0;
	int idx=-1;
	for(int i=0;i<n;i++){
        if(maxi<dp[i]){
			maxi=dp[i];
			idx=i;
		}
	}

	vector<int> ans(maxi);
	for(int i=maxi-1;i>=0;i--){
		ans[i]=arr[idx];
		idx=backtrack[idx];
	}

	return ans;
}
