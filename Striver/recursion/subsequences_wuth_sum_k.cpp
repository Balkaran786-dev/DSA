// this will be optimised once we do DP.
class Solution {
  public:
    void get_subsequences(vector<int>& arr,int idx,int &cnt,int sum,int target,int n){
        if(idx==n){
            if(sum==target){
                cnt++;
            }
            return;
        }
        
        get_subsequences(arr,idx+1,cnt,sum+arr[idx],target,n);
        get_subsequences(arr,idx+1,cnt,sum,target,n);
        
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int cnt=0;
        int idx=0;
        int sum=0;
        int n=arr.size();
        get_subsequences(arr,idx,cnt,sum,target,n);
        return cnt;
    }
};

