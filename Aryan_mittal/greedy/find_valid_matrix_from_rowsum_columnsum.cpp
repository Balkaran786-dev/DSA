// Find the smallest rowSum or colSum, and let it be x. Place that number in the grid, 
// and subtract x from rowSum and colSum. Continue until all the sums are satisfied.
class Solution {
    public:
        vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
            int numRows = rowSum.size();
            int numCols = colSum.size();
            vector<vector<int>> result(numRows, vector<int>(numCols, 0));
    
            int i = 0, j = 0;
    
            while (i < numRows && j < numCols) {
                int val = min(rowSum[i], colSum[j]);
                result[i][j] = val;
                rowSum[i] -= val;
                colSum[j] -= val;
    
                if (rowSum[i] == 0) {  // matlab agr rowsum voh vala 0 hogaya, toh uss saari row ke ele pe jab hum jakr min dekhenge , toh voh toh zero hi hoga, so we can skip them, so we moved down
                    i++;
                }
                if (colSum[j] == 0) { // matlab agr columnsum voh vala 0 hogaya, toh uss saari column ke ele pe jab hum jakr min dekhenge , toh voh toh zero hi hoga, so we can skip them, so we moved right
                    j++;
                }
            }
            return result;
        }
    };