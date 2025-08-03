class Solution {
public:
    vector<int> topo(vector<vector<int>> &graph,vector<int> &indegree){
        vector<int> ans;
        queue<int> qu;
        unordered_set<int> vis;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                qu.push(i);
                vis.insert(i);
            }
        }
        while(!qu.empty()){
           int node=qu.front();
           qu.pop();
           ans.push_back(node);
           for(auto neigh:graph[node]){
             indegree[neigh]--;
             if(indegree[neigh]==0){
                qu.push(neigh);
             }
           }
        }
        if(ans.size()!=graph.size()) return {};
        else return ans;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        //giving groups to loners
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i]=m++;
            }
        }

        //making graphs and indegree vector for items and groups
        vector<vector<int>> itemGraph(n),groupGraph(m);
        vector<int> itemIndegree(n,0),groupIndegree(m,0);
        
        //filling graphs and indegrees
        int sz=beforeItems.size();
        for(int i=0;i<sz;i++){
            int item=i;
            for(int j=0;j<beforeItems[item].size();j++){
                int itemBefore=beforeItems[item][j];
                itemGraph[itemBefore].push_back(item);
                itemIndegree[item]++;

                if(group[item]!=group[itemBefore]){
                    int groupItem=group[item];
                    int groupBeforeItem=group[itemBefore];
                    groupGraph[groupBeforeItem].push_back(groupItem);
                    groupIndegree[groupItem]++;
                }
            }
        }

        vector<int> group_topo=topo(groupGraph,groupIndegree);
        vector<int> item_topo=topo(itemGraph,itemIndegree);

        if(group_topo.empty() || item_topo.empty()) return {};

        unordered_map<int,vector<int>> GroupToItems;
        for(int i=0;i<item_topo.size();i++){
            int item=item_topo[i];
            GroupToItems[group[item]].push_back(item);
        }
        vector<int> ans;
        for(auto ele:group_topo){
             for(auto item:GroupToItems[ele]){
                ans.push_back(item);
             }
        }

        return ans;
    }
};