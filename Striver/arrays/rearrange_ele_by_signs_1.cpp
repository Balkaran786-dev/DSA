// equal number of positives and negatives are present...

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        if(nums.size()==2){
            if(nums[0]>0){
              return nums;
            }
            else{
                swap(nums[0],nums[1]);
                return nums;
            }
        }

        vector<int> ans(nums.size());
        int p=0,n=1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans[p]=nums[i];
                p+=2;
            }
            else{
                ans[n]=nums[i];
                n+=2;
            }
        }
        return ans;
    }
};
