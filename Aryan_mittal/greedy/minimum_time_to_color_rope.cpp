// jo subsequent equal color vale ballons mein se kam time lega, usko pehle remove krdenge..
// take two pointers, last and curr.

class Solution {
    public:
        int minCost(string colors, vector<int>& neededTime) {
            int last=0;
            int curr=1;
            int n=colors.size();
            if(n==1) return 0;
    
            int time=0;
            while(curr!=n){
                if(colors[last]==colors[curr]){
                    if(neededTime[last]<neededTime[curr]){
                        time+=neededTime[last];
                        last=curr;
                    }
                    else{
                        time+=neededTime[curr];
                    }
                }
                else last=curr;
                curr++;
            }
            return time;
        }
    };