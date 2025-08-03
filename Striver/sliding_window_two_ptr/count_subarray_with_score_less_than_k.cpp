class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            int n=nums.size();
            long long count=0;
            int l=0,r=0;
            long long sum=0;
            while(r<n){
                  sum+=nums[r];
                  while(1LL*sum*(r-l+1)>=k){
                    sum-=nums[l];
                    l++;
                  }
                  count+=(r-l+1);
                  r++;
            }
            return count;
        }
    };