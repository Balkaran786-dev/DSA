// this will make changes in the given array and we would not be able to restore the elements.
// using itself for hashing....


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0){
                nums[i]=n+1;
            }
        }

        for(int i=0;i<n;i++){
            int val=abs(nums[i]);
            if(val<=n && nums[val-1]>0){
                nums[val-1]*=-1;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0) return i+1;
        }

        return n+1;
    }
};

// cycle sort.
// through this, we will be able to restore the elements, but their position might be changed..

