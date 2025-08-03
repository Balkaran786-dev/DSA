class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            int n=nums.size();
            int min_l=0,min_u=0;
            int min_ele=INT_MAX;
            int max_ele=INT_MIN;
            long long ans=0;
            int l=0,r=0;
            while(r<n){
                if(nums[r]>maxK || nums[r]<minK){
                    min_l=r+1;
                    min_u=r+1;
                    min_ele=INT_MAX;
                    max_ele=INT_MIN;
                    r+=1;
                    l=r;
                    continue;
                }
                max_ele=max(max_ele,nums[r]);
                min_ele=min(min_ele,nums[r]);
                if(nums[r]==maxK) min_u=r;
                if(nums[r]==minK) min_l=r;
                if(min_ele==minK && max_ele==maxK){
                    ans++;
                    ans+=(min(min_l,min_u)-l);
                }
                r+=1;
            }
            return ans;
        }
    };