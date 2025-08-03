// (max ele apperaing at least k times= total subarrays- appearing at most k-1 times)
//
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n=nums.size();
            int max_ele=0;
            for(int i=0;i<n;i++){
                max_ele=max(max_ele,nums[i]);
            }
            
            unordered_map<int,int> mp;
            int l=0,r=0;
            long long count=0;
            while(r<n){
                mp[nums[r]]++;
                while(mp[max_ele]>k-1){
                    mp[nums[l]]--; 
                    l++;
                }
                count+=(r-l+1);
                r++;
            }
            return (1LL*n*(n+1)/2)-count;
        }
    };