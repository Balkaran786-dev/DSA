class Solution {
public:
    pair<int,int> dfs(int node,vector<vector<int>> &adj,vector<int>& quiet,vector<int> &ans){
        if(ans[node]!=-1) return {ans[node],quiet[ans[node]]};

        int val=node;
        int mini=quiet[node];
        for(auto neigh:adj[node]){
             pair<int,int> res=dfs(neigh,adj,quiet,ans);
             if(res.second<mini){
                mini=res.second;
                val=res.first;
             }
        }
        ans[node]=val;
        return {val,mini};
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<richer.size();i++){  //x->y means y is richer than x
            adj[richer[i][1]].push_back(richer[i][0]);
        }

        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                dfs(i,adj,quiet,ans);
            }
        }

        return ans;
    }
};