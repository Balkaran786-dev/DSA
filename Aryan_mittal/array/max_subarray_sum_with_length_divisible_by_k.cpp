// explained in daily leetcode copy.
class Solution {
    public:
        long long maxSubarraySum(vector<int>& nums, int k) {
            // while doing prefix,
            // we can do, pref(b)-pref(a), pref(b)-pref(a-k), pref(b)-pref(a-2k)..
            // all these indices, a,a-k,a-2k has a similar property that
            // they all gives same value upon i%k
    
            vector<long> min_prefix_sum(k,LLONG_MAX);  // k ke sath remainder krke 0 - k-1 takk hi rhenge...
            min_prefix_sum[k-1]=0;  // to handle one case..
            int n=nums.size();
            long long ans=LLONG_MIN;
            long long prefix_sum=0;
    
            for(int i=0;i<n;i++){
                prefix_sum+=nums[i];
                if(i>=k){
                    ans=max(ans,prefix_sum-min_prefix_sum[i%k]);
                }
                else if(i==k-1){
                    ans=max(ans,prefix_sum);
                }
                if(prefix_sum<min_prefix_sum[i%k]){
                    min_prefix_sum[i%k]=prefix_sum;
                }
            }
    
            return ans;
        }
    };