// explained in copy....
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int inc=1,dec=1;
        int max_length=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
                dec=1;
            }
            else if(nums[i]<nums[i-1]){
                inc=1;
                dec++;
            }
            else{
                inc=1;
                dec=1;
            }
            max_length=max(max_length,max(dec,inc));
        }
        return max_length;
    }
};