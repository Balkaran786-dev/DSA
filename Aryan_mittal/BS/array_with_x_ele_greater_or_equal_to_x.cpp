class Solution {
    public:
        int lower_bound(vector<int> &a,int value,int n){
        int lo=0;
        int hi=n-1;
        int ans=n;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(a[mid]>=value){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
         return ans;
        }
        int specialArray(vector<int>& nums) {
            int n=nums.size();
            sort(nums.begin(),nums.end());
            int lo=1;
            int hi=n;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                int x=lower_bound(nums,mid,n);
                if(n-x == mid) return mid;
                else if(n-x > mid){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
            return -1;
        }
    };