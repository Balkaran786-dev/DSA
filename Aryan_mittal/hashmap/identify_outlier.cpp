class Solution {
    public:
        int getLargestOutlier(vector<int>& nums) {
            int n=nums.size();
            
            int sum=0;
            int ans=INT_MIN;
            unordered_map<int,int> mp;
            for(int i=0;i<n;i++){
                mp[nums[i]]++;
                sum+=nums[i];
            }
    
            for(int i=0;i<n;i++){
                int val=sum-nums[i];
                if(!(val & 1) && mp.find(val/2)!=mp.end()){
                    if(val/2==nums[i] && mp[val/2]==1){  // may be it is possible ki nums[i] ko minus krne ke baad, jo val hai uska half voh nums[i] ke hi brbr ho, in that case voh nums[i] 2 se jada baar hona chahiye array mein , tabhi voh consider hoga as outlier.
                                                        // otherwise hum galti se usse hi sum of all numbers manlenge and outlier bhi 
                        continue;
                    }
                    ans=max(ans,nums[i]);
                }
            }
            return ans;
        }
    };