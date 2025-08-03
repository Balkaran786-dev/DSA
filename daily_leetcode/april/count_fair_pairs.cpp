class Solution {
    public:
        int get_idx(vector<int> &nums,int lower,int upper,int val,bool flag,int lo,int hi){
            int idx=-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]+val<lower){
                    lo=mid+1;
                }
                else if(nums[mid]+val>upper){
                    hi=mid-1;
                }
                else{         //inside range
                    idx=mid;
                    if(!flag){
                       hi=mid-1;
                    }
                    else{
                        lo=mid+1;
                    }
                }
            }
            return idx;
        }
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            int n=nums.size();
            sort(nums.begin(),nums.end());
            long long cnt=0;
            for(int i=0;i<=n-2;i++){
                int lower_b=get_idx(nums,lower,upper,nums[i],false,i+1,n-1); //false -> lower bound
                int upper_b=get_idx(nums,lower,upper,nums[i],true,i+1,n-1); // true -> upper bound
                if(lower_b!=-1 && upper_b!=-1){
                    cnt+=(upper_b-lower_b+1);
                }
            }
            return cnt;
        }
    };