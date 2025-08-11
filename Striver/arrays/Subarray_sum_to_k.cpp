//optimal
// here you are storing the freq aside to evry prefix sum..you know the concept;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int n=nums.size();
        mp[0]=1;
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
             sum+=nums[i];
             cnt+=mp[sum-k];
             mp[sum]++;
        }
        return cnt;
    }
};