// see the pattern...
// agr even number of negative numbers hain, we can anyway convert them into poistive numbers.
// agr odd number of negative numbers hain, one ele will be remained as negative, that we can make the one ,whose absolute value is the smallest....so that the resulting sum is very large...

class Solution {
    public:
        long long maxMatrixSum(vector<vector<int>>& matrix) {
            int n=matrix.size();
            long long sum=0;
            int neg=0;
            int min_val=INT_MAX;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                   if(matrix[i][j]<0) neg++;
                   sum+=abs(matrix[i][j]);
                   min_val=min(min_val,abs(matrix[i][j]));
                }
            }
    
            if(neg%2==0) return sum;
            return sum-(2*min_val);
        }
    };