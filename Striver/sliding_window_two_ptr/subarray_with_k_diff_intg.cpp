class Solution {  //o(2N) time
public:
    //very similar approachto binary subarrays sum
    //if we do simple sliding window, we will miss out on
    //so many subarrays hence it is easier to do it by
    //at most k vala method
    int subarray_K(vector<int>& nums, int k){
        if(k==0) return 0;
        int lo=0,hi=0,n=nums.size();
        int cnt=0;
        unordered_map<int,int> mp;
        while(hi<n){
            mp[nums[hi]]++;
            while(mp.size()>k){
                mp[nums[lo]]--;
                if(mp[nums[lo]]==0) mp.erase(nums[lo]);
                lo++;
            }

            cnt+=(hi-lo+1);
            hi+=1;
        }
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarray_K(nums,k)-subarray_K(nums,k-1);
    }
};