//11. 
// two pointer approach. why??
// because here everytime, we need to have a pair of lp and rp to calculate contained water.

class Solution {
public:
    int maxArea(vector<int>& vec) {
        int n=vec.size();
        int lp=0,rp=n-1;
        int area=INT_MIN;
        int width,height;
        while(lp<rp){
            width=rp-lp;
            height=min(vec[lp],vec[rp]);
            area=max(area,width*height);

            vec[rp]>vec[lp] ? lp++ : rp--;
        }
        return area;
    }
};