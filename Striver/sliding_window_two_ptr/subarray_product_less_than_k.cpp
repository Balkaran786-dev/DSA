class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            if(k==0) return 0;
            int lo=0,hi=0,cnt=0,product=1,n=nums.size();
           
            while(hi<n){
               product*=nums[hi];
               while(lo<=hi && product>=k){
                product/=nums[lo];
                lo+=1;
               }
               if(product<k){
                  cnt+=(hi-lo+1);
               }
               
               hi+=1;
            }
            return cnt;
        }
    };