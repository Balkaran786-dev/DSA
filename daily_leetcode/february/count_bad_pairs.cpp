// it will be  easier to count number of good pairs
// for good pairs the condition will be,
// j-i=nums[j]-nums[i],
// to make one side just for the characteristics of one ele,
// you can write nums[i]-i==nums[j]-j;

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            unordered_map<int, int> freq;
            long long goodPairs = 0, n = nums.size();
            
            for (int i = 0; i < n; i++) {
                int key = nums[i] - i;
                goodPairs += freq[key];
                freq[key]++;  // yeh baad mein hi krenge, kyunki for the first value of nums[i]-i, we don't have any corresponding pair.
                
            }
            
            return (n * (n - 1)) / 2 - goodPairs;
        }
};
