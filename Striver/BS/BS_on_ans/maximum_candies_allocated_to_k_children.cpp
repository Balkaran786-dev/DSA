class Solution {
    public:
        bool can_distribute(vector<int> &vec,long long k,int mid,int n){
            long long child=0;
            for(int i=0;i<n;i++){
                child+=(vec[i]/mid);
                if(child>=k) return true;
            }
            
            return false;
        }
        int maximumCandies(vector<int>& candies, long long k) {
            int n=candies.size();
            int lo=1;
            int hi=INT_MIN;
            for(int i=0;i<n;i++){
                hi=max(hi,candies[i]);
            }
    
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(can_distribute(candies,k,mid,n)){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
            return hi;
        }
    };