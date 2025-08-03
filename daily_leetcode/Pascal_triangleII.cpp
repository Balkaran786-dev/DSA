class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1); // Initialize with 1s
        long long current = 1; // Start with nC0 = 1
        
        for (int i = 1; i <= rowIndex-1; i++) {
            // Calculate nCr iteratively to avoid overflow
            current = current * (rowIndex - i + 1) / i;
            ans[i] = current;
        }
        
        return ans;
    }
};
