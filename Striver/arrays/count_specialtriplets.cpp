class Solution {
public:
    int MOD=1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp_left,mp_right;
        for(int i=1;i<n;i++){
            mp_right[nums[i]]+=1;
        }
        mp_left[nums[0]]+=1;
        int ans=0;
        for(int i=1;i<n-1;i++){
            mp_right[nums[i]]-=1;
            int left=mp_left[nums[i]*2];
            int right=mp_right[nums[i]*2];
            ans=(ans+(1LL*left*right)%MOD)%MOD;
            mp_left[nums[i]]+=1;
            
        }
        return ans;
    }
};