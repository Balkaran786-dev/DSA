// a lill bit similar to intervals question
// but we need to visualise kab humare do ya do se jada ballons ek hi arrow se burst ho jayege.
class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& points) {
            sort(points.begin(),points.end());
            int n=points.size();
            int finish=INT_MAX;
            int arrows=0;
            for(int i=0;i<n;i++){
                if(finish>=points[i][0]){
                    finish=min(finish,points[i][1]);
                }
                else{
                    arrows++;
                    finish=points[i][1];
                }
            }
            arrows++;
            return arrows;
        }
    };