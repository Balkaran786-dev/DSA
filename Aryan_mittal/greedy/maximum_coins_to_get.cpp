// mind this thing, bob should always get the least number of coins,
// we can't control alice, it will always take the greatest one, but we can control bob,
// rather than giving him greater, we can give him the least possible one...


class Solution {
    public:
        int maxCoins(vector<int>& piles) {
            sort(piles.begin(),piles.end());
            int n=piles.size();
            int y=n-2;
            int times=n/3;
            int sum=0;
            while(times--){
                sum+=piles[y];
                y-=2;
            }
            return sum;
        }
    };