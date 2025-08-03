#include<bits/stdc++.h>
using namespace std;

int get_LIS(int i, int n, int nums[], vector<int>& dp) {
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];

    int maxi = 1; 
    for (int next = i + 1; next < n; next++) {   
        if (nums[next] > nums[i]) {
            maxi = max(maxi, 1 + get_LIS(next, n, nums, dp));
        }
    }
    return dp[i] = maxi;
}

int longestIncreasingSubsequence(int nums[], int n) {
    vector<int> dp(n, -1);
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, get_LIS(i, n, nums, dp));
    }

    return maxi;
}

//2nd approach is take / not take approach.

/*
two things are changing, our current index, and prevIndex(iss ele ke basis per hi hum ele add krenge)
// not take doesn't add to our length so,
0+f(idx+1, prevIdx) 
// take only when curr ele is greater than prevele  or prevIndex ==-1
1+f(idx+1,idx) 

abb inn dono mein se jo max hoga voh return krdo,

dp vector is of n*n+1 size why n+1, beacuse to store at -1, we have done a coordinate change by shifting all values to right by unit 1,
so, we will store like dp[idx][prev_idx+1]=maxi;;

*/



#include <bits/stdc++.h> 
int get_LIS(int idx,int prev_idx,int n,vector<int> &heights,vector<vector<int>> &dp){
	if(idx==n) return 0;

	if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];

	int maxi=0;
	maxi=max(maxi,0+get_LIS(idx+1,prev_idx,n,heights,dp));
	if(prev_idx==-1 || heights[idx]>heights[prev_idx]){
		maxi=max(maxi,1+get_LIS(idx+1,idx,n,heights,dp));
	}
	return dp[idx][prev_idx+1]=maxi;
}

int LIS(vector<int> &heights, int n){	
	// Write your code here.
	vector<vector<int>> dp(n,vector<int> (n+1,-1));
	int idx=0;
	int prev_idx=-1;
	return get_LIS(idx,prev_idx,n,heights,dp);	
}



//tabulation
#include <bits/stdc++.h> 
int LIS(vector<int> &heights, int n){	
	// Write your code here.
	vector<vector<int>> dp(n+1,vector<int> (n+1,0));
	// dp[i][j] gives us the LIS from index i , if the prev_ele is on index j...
	for(int i=n-1;i>=0;i--){  
		for(int j=n-1;j>=-1;j--){
              int maxi=0;
			  maxi=max(maxi,0+dp[i+1][j+1]);
			  if(j==-1 || heights[i]>heights[j]){
				  maxi=max(maxi,1+dp[i+1][i+1]);
			  }
			  dp[i][j+1]=maxi;
		}
	}
	return dp[0][-1+1];
}


///space optimised
#include <bits/stdc++.h> 
int LIS(vector<int> &heights, int n){	
	// Write your code here.
	vector<int> curr(n+1,0);
	// dp[i][j] gives us the LIS from index i , if the prev_ele is on index j...
	for(int i=n-1;i>=0;i--){  
		vector<int> temp(n+1,0);
		for(int j=n-1;j>=-1;j--){
              int maxi=0;
			  maxi=max(maxi,0+curr[j+1]);
			  if(j==-1 || heights[i]>heights[j]){
				  maxi=max(maxi,1+curr[i+1]);
			  }
			  temp[j+1]=maxi;
		}
		curr=temp;
	}
	
	return curr[-1+1];
}


//tabulaution method  - basucally the tabulation form of my first approach at leetcode....
// dp[i] - represnt the LIS that ends at index i,


#include <bits/stdc++.h> 
int LIS(vector<int> &heights, int n){	
	// Write your code here.
	vector<int> dp(n,1);
	// dp[i][j] gives us the LIS from index i , if the prev_ele is on index j...
	for(int i=1;i<n;i++){
		int maxi=0;
		for(int j=0;j<i;j++){
           if(heights[j]<heights[i]){
			   maxi=max(maxi,dp[j]);
		   }
		}
		dp[i]+=maxi;
	}
	int maxi=0;
	for(int i=0;i<n;i++){
		maxi=max(maxi,dp[i]);
	}

	return maxi;
}




//binary search method..
// see the striver approach for this...

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> v;
    v.push_back(arr[0]);
    for(int i=1;i<n;i++){
        auto it = std::lower_bound(v.begin(), v.end(), arr[i]);
        if(it==v.end()){
            v.push_back(arr[i]);
        }
        else{
            v[it - v.begin()]=arr[i];
        }
    }

    return v.size();  //this v itself is not a LIS, but it length defines what max IS we can have..
    
}
