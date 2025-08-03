//similar to a lill bit topological sort bfs method...

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> outdegree(V,0);
        vector<vector<int>> indegree(V);
        for(int i=0;i<V;i++){
            outdegree[i]=graph[i].size();
            for(auto neigh:graph[i]){
                indegree[neigh].push_back(i);
            }
        }
        vector<int> safe_nodes;
        queue<int> qu;
        for(int i=0;i<V;i++){
            if(outdegree[i]==0) qu.push(i);
        }

        while(!qu.empty()){
            int ele=qu.front();
            qu.pop();
            safe_nodes.push_back(ele);
            for(auto neigh:indegree[ele]){
                outdegree[neigh]--;
                if(outdegree[neigh]==0){
                    qu.push(neigh);
                }
            }
        }
        sort(safe_nodes.begin(),safe_nodes.end());
        return safe_nodes;
    }
};