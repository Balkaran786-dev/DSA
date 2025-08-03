// my own code....
// simple line sweep algo
// look at this as horizontally and vertically
//to check for vertical cuts, you need x coordinates of intervals in a vector..
//to check for horizontal cuts, you need y coordinates of intervals in a vector..
// you must sort these intervals..
// to check for cuts, our first line of consideration is the ending of first interval,
// after that, if you get any interval whose starting of interval is >= curr cut, cuts++, and update your curr cut as ending of this interval
// if you get any inetrval whose starting of interval is < curr cut, update you curr_cut as max of curr_cut and ending of this interval...
// visualise kro.
// return cuts>=2...

class Solution {
    public:
        bool check(vector<vector<int> >&intervals,int n){
            sort(intervals.begin(),intervals.end());
            int curr=intervals[0][1];
            int cuts=0;
            for(int i=1;i<n;i++){
                
                if(curr<=intervals[i][0]){
                    cuts++;
                    curr=intervals[i][1];
                }
                else{
                    curr=max(curr,intervals[i][1]);
                }
            }
            return cuts>=2;
        }
        bool checkValidCuts(int n1, vector<vector<int>>& r) {
            int n=r.size();
            vector<vector<int>> x_intervals,y_intervals;
            for(int i=0;i<n;i++){
                x_intervals.push_back({r[i][0],r[i][2]});
                y_intervals.push_back({r[i][1],r[i][3]});
            }
    
            return check(x_intervals,n)||check(y_intervals,n);
        }
    };