//optimal o(n+m) time 
 


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0;
        int col=m-1;
        while(row<n && col>=0){   //starting from rightmost and topmost block....  you can also start from leftmost and bottomost block
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }
};