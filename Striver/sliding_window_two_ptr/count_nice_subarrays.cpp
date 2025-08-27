//similar to binary subarrys sum

class Solution {
public:
    int subarray_sum(vector<int>& nums, int k){
        if(k<0) return 0;
        int lo=0,hi=0,cnt=0,odd_nums=0,n=nums.size();
       
        while(hi<n){
           if(nums[hi]&(1)==1) odd_nums++;
           while(odd_nums>k){
            if(nums[lo]&(1)==1){
                odd_nums--;
            }
            lo+=1;
           }
           cnt+=(hi-lo+1);
           hi+=1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
         return subarray_sum(nums,k)-subarray_sum(nums,k-1);
    }
};



//if we do simple sliding window, we will miss out on so many subarrays.
//nums = [2,2,2,1,2,2,1,2,2,2], k = 2 checkout this example to know why we chose the above solu
