
class Solution {
  public:
    int get_count(int idx,int target,vector<int> &arr,vector<vector<int>> &dp,int n){
        
        
        
        if(idx==n-1){
            if(target==0 && arr[idx]==target) return 2;  //agr mera target already zero and last ele bhi zero hai, than 2 honge ways, ek baar include krke bhi ek baar exculde krke bhi
            else if(target==0) return 1; //if akela target hi zero hai,than also return 1 excluding the last ele,
            
            return (arr[idx]==target? 1 : 0);  // if target is equal to last ele, then return 1.
        }
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        int not_take=get_count(idx+1,target,arr,dp,n);
        int take=0;
        if(target>=arr[idx]){
            take=get_count(idx+1,target-arr[idx],arr,dp,n);
        }
        
        return dp[idx][target]= take + not_take;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        int idx=0;
        return get_count(idx,target,arr,dp,n);
    }
};

