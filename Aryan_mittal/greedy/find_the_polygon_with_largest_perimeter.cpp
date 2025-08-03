// think from the percpective of the largest edge, 
// to make the largest perimeter,every edge once it will be considered as largest will try 
//to take up all the smallest edges possible inside the polygon.

class Solution {
    public:
        long long largestPerimeter(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            long long sum=0;
            long long max_sum=-1;
            int n=nums.size();
            sum+=(nums[0]+nums[1]);
            for(int i=2;i<n;i++){
                if(sum>nums[i]){
                    max_sum=sum+nums[i];
                }
                sum+=nums[i];
            }
            return max_sum;
        }
    };