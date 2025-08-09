class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        vector<int> suffix_max(n);
        vector<int> suffix_min(n);
        suffix_max[n-1]=nums[n-1];
        suffix_min[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix_max[i]=max(suffix_max[i+1],nums[i]);
            suffix_min[i]=min(suffix_min[i+1],nums[i]);
        }
        long long ans=LLONG_MIN;
        for(int i=0;i<=n-m;i++){
             if(nums[i]>0){
                ans=max(ans,1LL*nums[i]*suffix_max[i+m-1]);
             }
             else{
                ans=max(ans,1LL*nums[i]*suffix_min[i+m-1]);
             }
        }
        return ans;
    }
};