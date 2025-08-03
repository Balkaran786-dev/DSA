// this will be optimised once we do DP.
bool get_subsequence(vector<int>& arr,int idx,int sum,int target,int n){
        if(sum==target){
            return true;
        }
        
        if(idx==n){
            return false;
        }
        
        bool res=get_subsequence(arr,idx+1,sum+arr[idx],target,n);
        if(res){
            return true;
        }
        return get_subsequence(arr,idx+1,sum,target,n);
}
bool isSubsetPresent(int n, int target, vector<int> &a)
{
    // Write your code here
    
        int idx=0;
        int sum=0;
        return get_subsequence(a,idx,sum,target,n);
        
}