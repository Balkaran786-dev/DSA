//2nd approach will be of at most vala thing..

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int n=nums.size();
            unordered_set<int> st;
            for(int i=0;i<n;i++) st.insert(nums[i]);
            int distinct=st.size();
    
            unordered_map<int,int> mp;
            int l=0,r=0;
            int ans=0;
            while(r<n){
                mp[nums[r]]++;
                while(l<n && mp.size()==distinct){
                    ans+=n-r;
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0) mp.erase(nums[l]);
                    l++;
                }
                r++;
            }
            return ans;
        }
    };