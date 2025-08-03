// preprocessing of prev_max and suffix min is all you need for this question

class Solution {
    public:
        int sumOfBeauties(vector<int>& nums) {
            int n=nums.size();
            vector<int> prev_max(n),suffix_min(n);
            prev_max[0]=nums[0];
            suffix_min[n-1]=nums[n-1];
            for(int i=1;i<n;i++){
                prev_max[i]=max(nums[i],prev_max[i-1]);
            }
            for(int i=n-2;i>=0;i--){
                suffix_min[i]=min(nums[i],suffix_min[i+1]);
            }
    
            int beauty=0;
            for(int i=1;i<=n-2;i++){
                if(nums[i]>prev_max[i-1] && nums[i]<suffix_min[i+1]) beauty+=2;
                else if(nums[i]>nums[i-1] && nums[i]<nums[i+1]) beauty+=1;
            }
            return beauty;
        }
    };