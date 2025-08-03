class Solution {
    public:
        int minSubArray(vector<int> &nums){
               int n=nums.size();
               int maxi=INT_MAX;
               int sum=0;
               for(int i=0;i<n;i++){
                sum+=nums[i];
    
                if(sum<maxi){
                    maxi=sum;
                }
    
                if(sum>0) sum=0;
                
               }
    
               return maxi;
        }
        int maxSubArray(vector<int> &nums){
               int n=nums.size();
               int maxi=INT_MIN;
               int sum=0;
               for(int i=0;i<n;i++){
                sum+=nums[i];
    
                if(sum>maxi){
                    maxi=sum;
                }
                if(sum<0) sum=0;
               }
    
               return maxi;
        }
        int maxAbsoluteSum(vector<int>& nums) {
            
            int max_sum=maxSubArray(nums);
            int min_sum=minSubArray(nums);
            return max(max_sum,abs(min_sum));
        }
};