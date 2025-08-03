// sorted ke wajah se yahan prefix and suffix kaam a gya..

class Solution {
    public:
        vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
            int n=nums.size();
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=nums[i];
            }
            
            vector<int> ans(n);
            
            ans[0]=sum-(n*nums[0]);
            int prefix=nums[0];
    
            for(int i=1;i<n;i++){
                prefix+=nums[i];
                int temp=sum-prefix;
                ans[i]=((nums[i]*(i+1))-prefix)+(temp-(nums[i])*(n-i-1));
            }
            return ans;
        }
    };