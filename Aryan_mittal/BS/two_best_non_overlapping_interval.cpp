class Solution {
    public:
        int get_smallerIdx(vector<vector<int>> &events,int endTime,int n){
            int lo=0;
            int hi=n-1;
            int idx=-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(events[mid][0]>endTime){
                    idx=mid;
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            return idx;
        }
        int maxTwoEvents(vector<vector<int>>& events) {
            int n=events.size();
            
            sort(events.begin(),events.end());
            vector<vector<int>> temp=events;
            int maxi=1;
            for(int i=n-1;i>=0;i--){
                maxi=max(events[i][2],maxi);
                events[i][2]=maxi;
            }
            int sum=0;
            for(int i=0;i<n;i++){
                int idx=get_smallerIdx(events,events[i][1],n);
                if(idx!=-1){
                    sum=max(sum,temp[i][2]+events[idx][2]);
                }
                else{
                    sum=max(sum,temp[i][2]);
                }
            }
            return sum;
        }
    };