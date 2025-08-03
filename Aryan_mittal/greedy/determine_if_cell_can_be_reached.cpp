class Solution {
    public:
        bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
            if(sx==fx && sy==fy && t==1) return false;
            int diff_x=abs(fx-sx);
            int diff_y=abs(fy-sy);
            int min_time=max(diff_x,diff_y);
            if(t>=min_time) return true;
            return false;
        }
    };