//if flag is true, it searches for first occ,if not it serches for last occ
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
    vector<int> searchRange(vector<int>& nums, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> ans;
        if(nums.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else if(nums.size()==1){
            if(nums[0]==target){
                ans.push_back(0);
                ans.push_back(0);
                return ans;
            }
            else{
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
        }
        else{
            int first=occ(nums,target,true);
            if(first==-1){
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
            else{
                int last=occ(nums,target,false);
                ans.push_back(first);
                ans.push_back(last);
                return ans;
            }
        }
        return ans;
    }
};