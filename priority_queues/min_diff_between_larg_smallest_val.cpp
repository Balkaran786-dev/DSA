class Solution {
    public:
        int minDifference(vector<int>& nums) {
           int n=nums.size();
           if(n<5) return 0;
           sort(nums.begin(),nums.end());
           int l=0;
           int r=n-4;
           int ans=INT_MAX;
           int cases=4;
           while(cases--){
              ans=min(ans,nums[r]-nums[l]);
              l++;
              r++;
           }
           return ans;
        }
};