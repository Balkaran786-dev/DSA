// ek point fix krke , uska dist saare points se niklkr ek map mein store krlo,
// then ek dist uss fixed point se jitni baar same aya, i mean uski freq jitni hogi,
// means utne points ka uss fixed point se dist same hoga,
// unme combinations hamare freq*freq-1 ke bnege.
// beacuse if n points ka dist uss ek point se same hai, then 1 point ke pass n-1 options hongi
// esse hi n points ke pass n*n-1 options hongi.


// we can also use nPr formula to find all possible combinations..


class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            for(int j=0;j<n;j++){
                int dist=((points[j][0]-points[i][0])*(points[j][0]-points[i][0]))+((points[j][1]-points[i][1])*(points[j][1]-points[i][1]));
                mp[dist]++;
            }


            for(auto ele:mp){   // here we nned to choose any two out of all ele.second points , we can use nPr,-> n!/(n-r)!  because here order matters....
                ans+=(ele.second)*(ele.second-1);
            }
        }
        return ans;
    }
};