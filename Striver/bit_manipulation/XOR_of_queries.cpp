//queries vala similar question array ke jaisa solv krna hai..

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
       int total_queries=queries.size();
       int n=arr.size();
       vector<int> ans(total_queries);
    
       //prefix_XOR calculation
       for(int i=1;i<n;i++){
        arr[i]=arr[i]^arr[i-1];
       }
       
       //finding queries
       for(int i=0;i<total_queries;i++){
            int idx_j = queries[i][0];
            int idx_i = queries[i][1];
            if (idx_j == 0) {
                ans[i] = arr[idx_i];
            } else {
                ans[i] = arr[idx_i] ^ arr[idx_j - 1];
            }
       }
       return ans;
    }
};