// 1st solution brute
// time-> o(n*m(n+m) + n*m)
// space-> o(1)

//Iterate over the matrix, when see any zero, iterate in that whole column and whole row, wherever you see
// 1 change it to -1, why not zero?? because that may cause some extra columns or row to be zero which should not be actually.
// after this, iterate through the matrix again, and whereever you see -1, change it to 0.




//2nd solution better
// time -> o(2(n*m)) 
// space -> o(n+m)

// we use two extra arrays one row array(n,0) and other column array (m,0);
// iterate through the matrix, when see a zero, mark one in the corresponding row array at index i and at index j in column array.

// now ,iterate through matrix, if you have 1 in matrix and if row[i]==0 || col[j]==0 , then mark it zero.


// 3rd solution optimal
// time -> o(2(n*m))
// space -> o(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int col0=1;
        // for col array ill use matrix[0][..];
        // for row array ill use matrix[..][0];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0=0;
                    }
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]!=0 && (matrix[i][0]==0 || matrix[0][j]==0)){
                    matrix[i][j]=0;
                }
            }
        }

        if(matrix[0][0]==0){
            for(int j=1;j<m;j++){
                matrix[0][j]=0;
            }
        }

        if(col0==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
    }

};