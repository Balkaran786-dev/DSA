class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        if(n==1) return 0;
        else if(n==2) return abs(arr[0]-arr[1]);
        
        vector<int> dp(n,-1);
        dp[n-1]=0;                           // energy lost if you r at the last stone
        dp[n-2]=abs(arr[n-1]-arr[n-2]);      // energy lost if you r at the second last stone
        for(int i=n-3;i>=0;i--){
            int value=INT_MAX;
            for(int idx=1;idx<=k;idx++){     
                if(i+idx>n-1)break;           // if it is out of bound, then you don't need to consider.....
                value=min(value,abs(arr[i+idx]-arr[i])+dp[i+idx]);
            }
            dp[i]=value;
        }
        return dp[0];
    }
};

