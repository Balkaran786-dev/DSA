
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
           mp[nums[i]]++;
        }
    
        int total_want=n/k;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end()){
                  continue;
            }
            else if(mp.find(nums[i]-1)!=mp.end()){
                continue;
            }
            else{
                int j=0;
                int val=k;
                while(val!=0 && mp.find(nums[i]+j)!=mp.end()){
                       val--;
                       mp[nums[i]+j]--;
                       if(mp[nums[i]+j]==0) mp.erase(nums[i]+j);
                       j++;
                }

                if(val!=0) return false;
                total_want--;
            }
        }
        if(total_want==0) return true;
        return false;
    }
};