class Solution {
public:
    int binary_search(vector<int>& nums, int target){
        int lo=0; //starting of the numsay
        int hi=nums.size()-1; //ending of the numsay
     while(lo<=hi){
        int mid=lo+(hi-lo)/2; 
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
     }
     return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            return (nums[0]==target? 0 : -1);
        }
        int lo=0;
        int hi=nums.size()-1;
        int ans=-1;
        if(nums[lo]<nums[hi]){
            return binary_search(nums,target);
        }
        
        while(lo<=hi){
        int mid=(hi+lo)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>=nums[lo]){
            if(target>=nums[lo] && target<=nums[mid]){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        else{
            if(target>=nums[mid] && target<=nums[hi]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
    }
    return -1;
    }
};