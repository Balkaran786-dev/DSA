
class Solution {
  public:
    vector<list<int>> graph;
    void add_edge(int source,int dest){ 
     graph[source].push_back(dest); 
    }
    void dfs(int i,unordered_set<int> &visited,stack<int> &st){
        visited.insert(i);
        for(auto neigh:graph[i]){
            if(!visited.count(neigh)){
                dfs(neigh,visited,st);
            }
        }
        st.push(i);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        graph.resize(V);
        int n=edges.size();
        for(int i=0;i<n;i++){
            int sorc=edges[i][0];
            int dest=edges[i][1];
            add_edge(sorc,dest);
        }
        stack<int> st;
        unordered_set<int> visited;
        for(int i=0;i<V;i++){
            if(!visited.count(i)){
                dfs(i,visited,st);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};

