//we just need to implement lower bound.....
//here,we r given that ll ele are distinct, hence we would return the ans
//as soon as we get mid value == target, otherwise, if mutiple ele were present, we need to find the 
//smallest index where ele value is equal to or just greater than the target.....

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
        if(ans==-1){  //yeh tabhi hoga , if the ele is greater than all te elements, so it won't be able to find any index where ele is greater than the target...
            return nums.size(); 
        }
        return ans;
    }
};