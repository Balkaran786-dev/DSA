// giving MLE for large testcases.
class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            int n=meetings.size();
            vector<int> freq(days,0);
            for(int i=0;i<n;i++){
               freq[meetings[i][0]-1]+=1;
               if(meetings[i][1]!=days){
                  freq[meetings[i][1]]-=1;
               }     
            }
    
            for(int i=1;i<days;i++){
               freq[i]+=freq[i-1];
            }
            
            int count=0;
            for(int i=0;i<days;i++){
                if(freq[i]==0) count++;
            }
            return count;
        }
    };