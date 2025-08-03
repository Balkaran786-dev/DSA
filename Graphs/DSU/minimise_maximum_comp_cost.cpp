class Solution {
public:
    static bool cmp(vector<int>& edg1, vector<int>& edg2) {
        return edg1[2] < edg2[2];
    }
    int find(vector<int>& par, int x) {
        return par[x] = (par[x] == x ? x : find(par, par[x]));
    }
    bool Union(vector<int>& par, vector<int>& Rank, int a,
               int b) { 
        a=find(par,a);
        b=find(par,b);
        if(a==b) return true;
        if (Rank[a] <= Rank[b]) {
            par[a] = b;
            Rank[b]++;
        } else {
            par[b] = a;
            Rank[a]++;
        }
        return false;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), cmp);
        int sz = edges.size();
        vector<int> par(n);
        vector<int> rank(n,1);
        for(int i=0;i<n;i++) par[i]=i;
        int i=0;
        vector<int> ans;
        while(i<sz){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            bool res=Union(par,rank,u,v);
            if(!res){
                ans.push_back(wt);
            }
            i++;
        }

        int rem=k-1;
        while(!ans.empty() && rem--){
            ans.pop_back();
        }

        int maxi=0;
        for(auto node:ans) maxi=max(maxi,node);

        return maxi;
    }
};