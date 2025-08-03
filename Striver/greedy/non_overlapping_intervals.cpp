/*
we sorted through end time, because may be there is a large interval that is  covering 
two three intervals inside it, so rather than removing the two three intervals,
we need to remove the larger interval as we need to minimise this removal.
hence these two three interval will come before the larger interval if we sort them like this,
hence we won't removing them.  
*/
class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2){
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);

        int removed_intervals=0;
        int n=intervals.size();
        vector<int> last_interval=intervals[0];
        for(int i=1;i<n;i++){
           if(intervals[i][0]<last_interval[1]){
            removed_intervals++;
           }
           else{
            last_interval=intervals[i];
           }
        }
        return removed_intervals;
    }
};