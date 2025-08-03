//brute force..
//o(n*m) going in each row checking which row has the least column where 1 occurred....
//or you can count the 1s also...





//optimal solution  n*logm time 
int LowerBound(vector<vector<int>> &matrix,int m,int i){
    int lo=0;
    int hi=m-1;
    int ans=m;   //this is set beacuse if no 1s will be present , ans = m will be returned , nicche CntOnes  will come out as 0 in that case
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(matrix[i][mid]>=1){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    // Write Your Code Here
    int CntMax=0;
    int index=-1;
    for(int i=0;i<n;i++){
        int CntOnes=m-LowerBound(matrix,m,i);
        if(CntOnes>CntMax){
            CntMax=CntOnes;
            index=i;
        }
    }

    return index;
}