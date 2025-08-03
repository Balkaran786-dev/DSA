



//analogy similar to chocolate prob
class Solution {
public:
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
    int splitArray(vector<int>& nums, int k) {
        //analogy to chocolate prob
        // here elimination based on number of subarrays you formed,
        // lo=max of all()
        // hi=sum of all() -> subarrays will be one
        // if subarrays coming less or equal to k , move to left
        // if subarrays coming greater than k, move to right
        int n=nums.size();
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        int lo=maxi;
        int hi=sum;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(nums,mid,k,n)){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
        
    }
};