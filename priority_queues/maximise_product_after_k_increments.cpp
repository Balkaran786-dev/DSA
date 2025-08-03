class Solution {
public:
    int MOD=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return nums[0]+k;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++) pq.push(nums[i]);

        while(k--){
            int val=pq.top(); pq.pop();
            pq.push(val+1);
        }
         
        int ans=1;
        while(!pq.empty()){
            ans=(1LL*ans*pq.top())%MOD;
            pq.pop();
        }

        return ans;
    }
};