// preprocessing is all you need in this question
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n=nums.size();
            int prev_max=nums[0];
            vector<int> next_max(n,-1);
            next_max[n-1]=nums[n-1];
            for(int i=n-2;i>=0;i--){
                next_max[i]=max(nums[i],next_max[i+1]); 
            }
            
            long long value=0;
            for(int i=1;i<=n-2;i++){
                value=max(value,1LL*(prev_max-nums[i])*next_max[i+1]);
                prev_max=max(prev_max,nums[i]);
            }
    
            return value;
        }
    };


// 2012. a very similar question:-
// sum of beauty of array...

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