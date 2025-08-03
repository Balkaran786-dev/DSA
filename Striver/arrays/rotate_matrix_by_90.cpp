// using an extra n*n matrix,
// put the first row in last column,
// then put the second row in second last column and so on..




// this second method make use of transpose 
// transpose of n*m matrix can be forund by using a extra m*n matrix,
// but here we have n*n matrix, so we can save this extra space..

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i!=j && i<j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};