// just prefix sum approach..
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> vec(n);
        vec[0]=nums[0];
        for(int i=1;i<n;i++){
            vec[i]=nums[i]+vec[i-1];
        }

        int splits=0;
        long long total_sum=vec[n-1];
        for(int i=0;i<=n-2;i++){
            if(total_sum-vec[i]<=vec[i]) splits++;
        }
        return splits;
    }
};