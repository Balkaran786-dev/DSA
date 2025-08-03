class Solution{  
public:
    bool search(vector<vector<int>> &matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==1 && m==1){
            return matrix[0][0]==target;
        }
        int lo=0;
        int hi=n*m-1;
        int x,y;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            x=mid/m;
            y=mid%m;
            if(matrix[x][y]==target){
                return true;
            }
            else if(matrix[x][y]>target){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return false;
    }
};