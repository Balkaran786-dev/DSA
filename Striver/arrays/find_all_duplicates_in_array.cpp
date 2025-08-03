// use the same method as used in find the duplicate number..
// using array itself for hashing..


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
             int val= abs(nums[i]);
             if(nums[val-1]<0){
                ans.push_back(val);
             }
             else{
                nums[val-1]*=-1;
             }
        }
        return ans;
    }
};