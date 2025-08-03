

class Solution {
    public:
        int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
            sort(points.begin(),points.end());
            int start=points[0][0];
            int n=points.size();
            int rec=0;
            for(int i=1;i<n;i++){
                  if(start+w<points[i][0]){
                      rec++;
                      start=points[i][0];
                  }
            }
            return rec+1;
        }
    };