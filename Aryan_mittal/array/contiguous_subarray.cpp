class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // transformed this question into
        // maximum subarray with sum=0.
        // we mapped 0 -> -1 and 1 -> 1
        
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=-1;
        int max_len=0;
        int sum=0;
        for(int i=0;i<n;i++){
             if(nums[i]==0){
                 sum-=1;
             }
             else{
                sum+=1;
             }
            
             if(mp.find(sum)!=mp.end()){
                max_len=max(max_len,i-mp[sum]);
             }
             else{
                mp[sum]=i;
             }
        }
        return max_len;
    }
};