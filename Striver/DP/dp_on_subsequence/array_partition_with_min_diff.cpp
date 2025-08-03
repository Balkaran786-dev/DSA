// dp[i][j] basucally tells, ki from ith index, can i achieve j value,

// dp[0][0.....target]  this tells us what values we can achieve from 0 to target from our array after forming subsets.
// so, whatever sum im able to achieve , assume it as the sum of first subset and second subset sum can be achieved from total sum-subset sum1,
// so, you can find the minimum among all....


int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int target=0;
	for(int i=0;i<n;i++){
		target+=arr[i];
	}

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

	int mini=INT_MAX;
	for(int i=0;i<target+1;i++){
		if(prev[i]==true){
			mini=min(mini,abs((target-i)-i));
		}
	}
	return mini;
}
