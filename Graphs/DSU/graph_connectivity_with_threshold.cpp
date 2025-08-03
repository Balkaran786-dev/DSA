//good use of divisors + UNion find

class Solution {
public:
    int Find(vector<int>& par, int x) {
        return par[x] = (par[x] == x ? x : Find(par, par[x]));
    }
    void Union(vector<int>& par, vector<int>& rank, int a, int b) {
        a = Find(par, a);
        b = Find(par, b);
        if(a==b) return;
        if (rank[a] <= rank[b]) {
            par[a] = b;
            rank[b]++;
        } else {
            par[b] = a;
            rank[a]++;
        }
    }
    vector<bool> areConnected(int n, int threshold,
                              vector<vector<int>>& queries) {
        vector<int> par(n + 1);
        vector<int> rank(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
        for (int num = 2; num <= n; num++) {
            for (int i = 1; i <= sqrt(num); i++) {
                if (num % i == 0 ) {
                  if(i>threshold) Union(par,rank,i,num);
                    if (num / i != i) {
                       if((num/i)>threshold) Union(par,rank,num/i,num);
                    }
                }
            }
        }
        int q=queries.size();
        vector<bool> ans(q);
        for(int i=0;i<q;i++){
            if(Find(par,queries[i][0])==Find(par,queries[i][1])){
                ans[i]=true;
            }
            else ans[i]=false;
        }
        return ans;
    }
};