// okay approach but yeah some optimisation can occur
// approach:-
// main aim of 1st robot is to minimise the profit of second ribot
// explained in copy in detail.


class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
         ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);

        int n=grid[0].size();
        vector<vector<long long>> vec(2,vector<long long> (n));

        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                vec[i][j]=grid[i][j];
            }
        }
        for(int i=n-2;i>=0;i--){
           vec[0][i]+=vec[0][i+1];
        }
        for(int i=1;i<=n-1;i++){
            vec[1][i]+=vec[1][i-1];
        }
        
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            long long upper_sum=(i+1==n?0:vec[0][i+1]);
            long long lower_sum=(i-1==-1?0:vec[1][i-1]);
            ans=min(ans,max(upper_sum,lower_sum));
        }
        return ans;
    }
};

//same approach but yeah a lill optimised.

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long result = LLONG_MAX;
        long long top_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bottom_sum = 0;

        for (int i = 0; i < grid[0].size(); ++i) {
            top_sum -= grid[0][i];
            result = min(result, max(top_sum, bottom_sum));
            bottom_sum += grid[1][i];
        }

        return result;
    }
};