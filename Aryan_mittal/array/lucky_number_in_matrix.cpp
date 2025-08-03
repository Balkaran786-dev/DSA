//Find position for min in row, then test it if max in column.

// here you can avoid the extra space of vector....
// traverse through a row, save the column of the smallest index in a variable
// now traverse through that variable...
// o(n*(n+m))->time  
// o(1)->space

// we would be having at most one magic number..
// proof by contradiction.
// taking two numbers as lucky numbers.(Y , X)
// and then taking two diff integers in their respective rows(A,B)
// one will show, Y>X  and other will show X<Y
// hence it will be contradictory.
// so, atmost one lucky number.

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> minPos(m, -1);
        for(int i=0; i<m; i++){
            int p=min_element(matrix[i].begin(), matrix[i].end())-matrix[i].begin();
            minPos[i]=p;
        }
        
        vector<int> ans;
        for(int i=0; i<m; i++){
            int p=minPos[i], x=matrix[i][p];
            bool lucky=1;
            for(int j=0; j<m; j++){
                if (matrix[j][p]>x){
                    lucky=0;
                    break;
                }
            }
            if (lucky) ans.push_back(x);
        }
        return ans;
    }
};