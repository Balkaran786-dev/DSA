class Solution {
    public:
        void flip_row(vector<int> &row,int n){
            for(int i=0;i<n;i++){
                if(row[i]==0) row[i]=1;
                else row[i]=0;
            }
        }
        int matrixScore(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
    
            for(int i=0;i<m;i++){
               if(grid[i][0]==0){
                flip_row(grid[i],n);
               }
            }
            for(int j=1;j<n;j++){
                int cnt=0;
                for(int i=0;i<m;i++){
                    if(grid[i][j]==0) cnt++;
                }
                if(cnt>m/2){
                    for(int i=0;i<m;i++){
                        if(grid[i][j]==0) grid[i][j]=1;
                        else grid[i][j]=0;
                    }
                }
            }
            int sum=0;
            for(int i=0;i<m;i++){
                  int num=0;
                  int power=0;
                  for(int j=n-1;j>=0;j--){
                      num+=(grid[i][j]*pow(2,power));
                      power++;
                  }
                  sum+=num;
            }
            return sum;
        }
    };