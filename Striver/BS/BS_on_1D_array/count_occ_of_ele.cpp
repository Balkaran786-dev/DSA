
class Solution {
  public:
  
    int occ(vector<int> &v,int target,bool flag){
        int lo=0;
        int hi=v.size()-1;
        int ans=-1;
        int mid;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(v[mid]==target){
                ans=mid;
                if(flag){
                   hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            else if(v[mid]<target){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
    int countFreq(vector<int>& nums, int target) {
        // code here
        if(nums.size()==1){
            if(nums[0]==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            int first=occ(nums,target,true);
            if(first==-1){
                return 0;
            }
            else{
                int last=occ(nums,target,false);
                return last-first+1;
            }
        }
        return 0;
    }
};

