

// very similar to split array max question
bool f(vector<int>& nums,int mid, int k,int n){
        int CurrSum=0;
        int subarrays=1;
        for(int i=0;i<n;i++){
            if(nums[i]>mid)return false;
            else if(CurrSum+nums[i]>mid){
                CurrSum=nums[i];
                subarrays++;
                if(subarrays>k) return false;
            }
            else{
                CurrSum+=nums[i];
            }
        }
        return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int n=boards.size();
        int maxi=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,boards[i]);
            sum+=boards[i];
        }
        int lo=maxi;
        int hi=sum;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(boards,mid,k,n)){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
}