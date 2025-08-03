// so basically based on prefix sums ans suffix sum..

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n=possible.size();
        int bob_points=0;
        for(int i=0;i<n;i++){
            if(possible[i]==0) bob_points-=1;
            else bob_points+=1;
        }
        
        int alice_points=0;
        for(int i=0;i<n-1;i++){  // obviously alice can't play all the levels, so that's why n-2 tak hi voh maximum ja skta hai, bob ko ek level toh khelna hi hoga.
            if(possible[i]==0){
                alice_points-=1;
                bob_points+=1;
            }
            else{
                alice_points+=1;
                bob_points-=1;
            }

            if(alice_points>bob_points) return i+1;
        }
        return -1;
    }
};