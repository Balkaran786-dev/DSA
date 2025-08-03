//in o(1) space complexity
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool flag1=false;
        bool flag2=false;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
                flag1=true;
                break;
            }
        }
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                flag2=true;
                break;
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0 && i!=0){
                for(int j=1;j<matrix[0].size();j++){
                    matrix[i][j]=0;
                }
            }
        }

        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                for(int i=1;i<matrix.size();i++){
                    matrix[i][j]=0;
                }
            }
        }

        if(flag2){
            for(int j=0;j<matrix[0].size();j++){
                matrix[0][j]=0;
            }
        }
        if(flag1){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
    }
};