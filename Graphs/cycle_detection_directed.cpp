
class Solution {
  public:
    vector<list<int>> graph;
    void add_edge(int source,int dest){ 
     graph[source].push_back(dest); 
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        graph.resize(V);
        int n=edges.size();
        for(int i=0;i<n;i++){
            int sorc=edges[i][0];
            int dest=edges[i][1];
            add_edge(sorc,dest);
        }
        
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto neigh:graph[i]){
                indegree[neigh]++;
            }
        }
        
        queue<int> qu;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) qu.push(i);
        }
        
        int done=0;
        
        while(!qu.empty()){
            int ele=qu.front();
            qu.pop();
            done++;
            for(auto neigh:graph[ele]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    qu.push(neigh);
                }
            }
        }
        
        return (done==V? false:true); 
    }
};


