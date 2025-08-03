// divide kaise krna hai,
// jo abhi hum mid le rhe hain , usme divide krte jayenga,
// i mean i is total balls, then we will will divide as mid and i-mid then further this,,but that will be calculated in ceil value itself....

class Solution {
    public:
        bool can_dist(vector<int> &nums,int mid,int maxOperations){
            int div=0;
            for(int i=0;i<nums.size();i++){
                div+=(ceil((double)nums[i]/mid)-1);
                if(div>maxOperations) return false;
            }
            return true;
        }
        int minimumSize(vector<int>& nums, int maxOperations) {
            // till now, what i can think of is using a priority queue..
            // that will give us..
             ios_base::sync_with_stdio(0);
                cin.tie(0);
                cout.tie(0);
    
            int n=nums.size();
            int lo=1;
            int hi=-1;
            for(int i=0;i<n;i++){
                hi=max(hi,nums[i]);
            }
            
            int ans=lo;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(can_dist(nums,mid,maxOperations)){
                    ans=mid;
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            return ans;
        }
    };