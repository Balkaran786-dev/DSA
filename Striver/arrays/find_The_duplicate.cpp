// same approach as of first missing positive number,
// using array itself for hashing...

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int val=abs(nums[i]);
            if(nums[val-1]<0){
                return val;
            }
            else{
                nums[val-1]*=-1;
            }
        }
        return -1;
    }
};