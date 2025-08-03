
//optimal solution Binary search:-
// very similar approach to koko eating banana...
class Solution {
public:
    bool satisfied(vector<int>& nums,int mid,int threshold,int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)nums[i]/(double)mid);
            if(sum>threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int lo=1;
        int hi=INT_MIN;
        for(int i=0;i<n;i++){
            hi=max(hi,nums[i]);
        }
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(satisfied(nums,mid,threshold,n)){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
};