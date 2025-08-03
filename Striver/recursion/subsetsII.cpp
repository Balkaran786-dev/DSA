// o(nlogn + 2^n) time
// o(n+ n*2^n) space
class Solution {
public:
    void get_subsets(vector<int> &nums,int idx,int n,vector<vector<int>>&ans,vector<int> temp){
        if(idx==n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        get_subsets(nums,idx+1,n,ans,temp);
        temp.pop_back();
        int j=idx+1;   //while rejecting, im rejecting all the ele similar to it to avoid duplicacies..
        while(j<n && nums[j]==nums[j-1]) j++;
        get_subsets(nums,j,n,ans,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int idx=0;
        vector<vector<int>> ans;
        vector<int> temp;
        get_subsets(nums,idx,n,ans,temp);
        return ans;
    }
};