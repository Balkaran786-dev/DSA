// sort and pass by value is required , due to the reasons given in copy.
 
class Solution {
public:
    void get_all_permutations(vector<int> vec, int idx, int n, int change,
                              vector<vector<int>>& ans) {
        if (idx == n) {
            ans.push_back(vec);
            return;
        }

        for (int i = idx; i < n; i++) {
            if(i!=change && vec[i]==vec[change]) continue;
            swap(vec[i], vec[change]);
            get_all_permutations(vec, idx + 1, n, change + 1, ans);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int idx = 0;
        int change = 0;
        int n = nums.size();
        get_all_permutations(nums, idx, n, change, ans);
        return ans;
    }
};