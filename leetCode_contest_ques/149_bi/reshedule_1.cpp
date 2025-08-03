//1.
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<vector<int>> events(n,vector<int> (2));
        for(int i=0;i<n;i++){
            events[i][0]=startTime[i];
            events[i][1]=endTime[i];
        }

        sort(events.begin(),events.end());
        vector<int> gap_array(n+1);
        
        gap_array[0]=startTime[0];

        for(int i=1;i<n;i++){
            gap_array[i]=(events[i][0]-events[i-1][1]);
        }
        gap_array[n]=eventTime-endTime.back();

        int current_sum=0;
        int max_sum=0;
        for(int i=0;i<n+1;i++){
            current_sum+=gap_array[i]-(i>=k+1? gap_array[i-(k+1)]:0);
            max_sum=max(max_sum,current_sum);
        }
        return max_sum;
    }
};