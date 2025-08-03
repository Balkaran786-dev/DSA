//just we need to find if we got the target itself return its idx,
//if the mid is greater than target, means it can be a possible place to insert,
//so ans mein usse save krlo and move to the left side,
//if the mid is smaller than target, just simply move to right,

//at the end, if ans has something in it rather than -1, return it
//if it is -1, means the target is greater than all the numbers, hence return numn.size()....

class Solution {
public:
    int searchInsert(vector<int>& nums, int target){
        int lo=0;
        int hi=nums.size()-1;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]==target){
                ans=mid;
                break;
            }
            else if(nums[mid]>target){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        if(ans==-1){
            return nums.size();
        }
        return ans;
    }
};