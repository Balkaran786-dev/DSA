//explanation:-
//hum mid nikalenge taking lo=0 hi=m-1
// jo mid nikla , uss column mein sabse jada probability peak ele bnne ki kisi hogi??
// jo sabse large hoga, because that is surely gonna be larger than upper and lower element.
// abh for that element, if it is greater than its left and right ele, return this as ans.
// if not, that ,if its leftelement is bigger than it, there is surety that there will be peak ele in left side, hence hi=mid-1;
// same for right ele, if it is larger.



vector<int> findPeakGrid(vector<vector<int>> &mat){
    // Write your code here. 
    
    int n=mat.size();
        int m=mat[0].size();
        if(n==1 && m==1) return {0,0};   //only a aingle ele...
        int lo=0;
        int hi=m-1;
        while(lo<=hi){
             int mid=lo+(hi-lo)/2;
             int maxi_ele=-1;
             int row=-1;

             for(int i=0;i<n;i++){
                if(mat[i][mid]>maxi_ele){
                    maxi_ele=mat[i][mid];
                    row=i;
                }
             }

             if(mid==0){
                if(m==1) return {row,mid};  //if in case there is only one column.
                if(mat[row][mid+1]<maxi_ele) return {row,mid};
                else lo=mid+1;
             }
             
             else if(mid==m-1){
                if(mat[row][mid-1]<maxi_ele) return {row,mid};
                else hi=mid-1;
             }
             else{
                if(mat[row][mid+1]<maxi_ele && mat[row][mid-1]<maxi_ele) return {row,mid};
                else if(mat[row][mid+1]>maxi_ele) lo=mid+1;
                else hi=mid-1;
             }
        }
        return {-1,-1};   
}