/*
1. no_of_breakpoints means you get a place where nums[i]>nums[i+1]
it can be atmost 1,if it is more than 1,than obviously it is not rotated sorted,

2. if no_of breakpoints are 1,that means the last element should be either lesser than or 
equal to the first ele,if it doesn't follow,return false; // for ex:- 1,5,1,2,3 here breakpoints are 1, but not rotated sorted....

otherwise it is true in all other cases.*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int no_of_breakPoints=0;
        for(int i=0;i<n-1;i++){
           if(nums[i]>nums[i+1]){
            no_of_breakPoints++;
            if(no_of_breakPoints>1) return false;
           }
        }
        
        if(no_of_breakPoints!=0 && nums[0]<nums[n-1]){
                 return false;
        }
        
        return true;
    }
};