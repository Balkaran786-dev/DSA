//1st solution:- o(n^2) time and o(1) space
//generating all subarrays. whenever whose sum gets equal to k, do cnt++;


//2nd solution:- hashing.....o(n) both time and space
//hashing solution is already done in count subarray whose sum is equal to k.



//3rd solution:-  explained in copy..
class Solution {
public:
    int subarray_sum(vector<int>& nums, int goal){  //basically return all subarrays whose sum<=goal..
        if(goal<0) return 0;
        int lo=0,hi=0,cnt=0,sum=0,n=nums.size();
       
        while(hi<n){
           sum+=nums[hi];
           while(sum>goal){
            sum-=nums[lo];
            lo+=1;
           }
           cnt+=(hi-lo+1);
           hi+=1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarray_sum(nums,goal)-subarray_sum(nums,goal-1);
    }
};
