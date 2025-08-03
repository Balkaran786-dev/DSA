// explained in copy
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();

        vector<int> free_gaps(n+1);

        free_gaps[0]=startTime[0];
        for(int i=1;i<n;i++){
            free_gaps[i]=startTime[i]-endTime[i-1];
        }

        free_gaps[n]=eventTime-endTime.back();

        vector<int> right_largest(n+1,0);
        for(int i=n-1;i>=0;i--){
            right_largest[i]=max(right_largest[i+1],free_gaps[i+1]);
        }

        vector<int> left_largest(n+1,0);
        for(int i=2;i<=n;i++){
            left_largest[i]=max(left_largest[i-1],free_gaps[i-2]);
        }

        int max_free_time=0;
        for(int i=1;i<=n;i++){
           int meetingTime=endTime[i-1]-startTime[i-1];
           if(meetingTime<=max(left_largest[i],right_largest[i])){
              max_free_time=max(max_free_time,meetingTime+free_gaps[i]+free_gaps[i-1]);
           }
           max_free_time=max(max_free_time,free_gaps[i]+free_gaps[i-1]);
        }
        return max_free_time;
    }
};