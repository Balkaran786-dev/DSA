// overlapping 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        vector<int> last={intervals[0][0],intervals[0][1]};

        for(int i=1;i<n;i++){

            // why we applied the second condition with and??
            // Because it can be possible that the interval start before the end of last interval, but may be
            // it also ends before the end of the last interval. like, last ->(1,6)  next->(4,5)
            //if it ends before the end of the last interval, we need to ingore it, because it is already covered in the last interval.

            if(last[1]>=intervals[i][0] && last[1]<=intervals[i][1]){ 
                last[1]=intervals[i][1];
            }
            else if(last[1]<intervals[i][0]){
                ans.push_back(last);
                last=intervals[i];
            }
        }
        ans.push_back(last);
        return ans;
    }
};