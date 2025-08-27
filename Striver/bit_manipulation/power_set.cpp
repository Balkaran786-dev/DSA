//1st solution can be recursive..


//2nd solution using bitwise operator.explained in copy   o(n*2^n) both space and time
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        int total_subsets=1<<n;

        for(int i=0;i<total_subsets;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if((i&(1<<j))!=0){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
