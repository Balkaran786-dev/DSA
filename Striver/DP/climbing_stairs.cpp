// using space optimised tabulation..
class Solution {
    public:
        int climbStairs(int n) {
            if(n==1) return 1;
            int a=1,b=1;
            int curr=-1;
            for(int i=2;i<=n;i++){
                 curr=a+b;
                 a=b;
                 b=curr;
            }
            return curr;
        }
    };

    