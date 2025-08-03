// based on prefix 
// but a lill different..
// expalined in copy...

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> prefix(n,0);  // 0th index pe toh obviously 0 hi rhekenge, beacuse uske piche kuch hai hi nhi...
        for(int i=1;i<n;i++){
              prefix[i]=prefix[i-1];
              if(nums[i]%2==nums[i-1]%2){
                prefix[i]++;
              }
        }
        
        int sz=queries.size();
        vector<bool> ans(sz);
        for(int i=0;i<sz;i++){
           int q1=queries[i][0];
           int q2=queries[i][1];

           int count=prefix[q2]-prefix[q1];
           ans[i]=(count>=1? false:true);
        }
        return ans;
    }
};