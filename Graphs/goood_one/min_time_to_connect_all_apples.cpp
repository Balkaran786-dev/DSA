class Solution {
public:
    bool dfs(int node,int &ans,vector<vector<int>> &graph,unordered_set<int> &visited,vector<bool>& hasApple){
        visited.insert(node);
        bool flag = hasApple[node];
        
        for(auto neigh:graph[node]){
            if(!visited.count(neigh)){
                ans+=1;
                bool res=dfs(neigh,ans,graph,visited,hasApple);
                if(res==false) ans-=1;
                else{
                    flag = true;
                    ans+=1;
                }
            }
        }
        return flag;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        int ans=0;
        unordered_set<int> visited;
        dfs(0,ans,graph,visited,hasApple);
        return ans;
    }
};