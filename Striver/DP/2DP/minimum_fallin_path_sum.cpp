// tabulation

class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n=matrix.size();
            vector<int> prev(n);
            for(int i=0;i<n;i++){
                prev[i]=matrix[n-1][i];
            }
    
            for(int i=n-2;i>=0;i--){
                vector<int> temp(n);
                for(int j=n-1;j>=0;j--){
                    int mini=INT_MAX;
                    if(j+1<n) mini=min(mini,prev[j+1]);
                    if(j-1>=0) mini=min(mini,prev[j-1]);
                    mini=min(mini,prev[j]);
                    temp[j]=matrix[i][j]+mini;
                }
                prev=temp;
            }
    
            return *std::min_element(prev.begin(), prev.end());
        }
    };
