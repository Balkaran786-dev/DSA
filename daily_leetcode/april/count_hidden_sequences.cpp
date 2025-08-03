class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int n=differences.size();
            long long prefix=0;
            long long min_diff=LLONG_MAX,max_diff=LLONG_MIN;
    
            for(int i=0;i<n;i++){
                prefix+=differences[i];
                min_diff=min(min_diff,prefix);
                max_diff=max(max_diff,prefix);
            }
            
            int cnt=0;
    
            for(int i=lower;i<=upper;i++){
                long long min_val=min_diff+i;
                long long max_val=max_diff+i;
                if(min_val>=lower && max_val<=upper) cnt++;
            }
    
            return cnt;
        }
    };