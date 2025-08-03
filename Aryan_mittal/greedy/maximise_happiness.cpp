class Solution {
    public:
        long long maximumHappinessSum(vector<int>& happiness, int k) {
            sort(happiness.rbegin(), happiness.rend());  // Sort in descending order
            long long sum = 0;
            int decrease = 0;
    
            for (int i = 0; i < k; i++) {  
                int val = max(0, happiness[i] - decrease);  // Ensure happiness doesn't go negative
                sum += val;
                decrease++;  // Increase decrease count for subsequent selections
            }
    
            return sum;
        }
    };
    