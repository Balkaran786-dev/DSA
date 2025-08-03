class Solution {  //in case of disconnected graph,if all cc are bipartite,
                 //then the whole graph is bipartite.
                 //if even a single cc is not bipartite,then whole is non bipartite
public:
    queue<int> qu;
    vector<int> nature;
    bool bfs(int sorc,vector<vector<int>>& graph){
        int color=0;  //RED  !0 = 1-> BLUE
        qu.push(sorc);
        nature[sorc]=0;
        while(!qu.empty()){
            int curr=qu.front();
            qu.pop();
            for(int neigh:graph[curr]){
                if(nature[neigh]==-1){
                    qu.push(neigh);
                    nature[neigh]=!nature[curr];
                }
                else{
                    if(nature[neigh]==nature[curr]) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        nature.resize(n,-1);
        for(int i=0;i<n;i++){
            for(auto neigh:graph[i]){
                if(nature[neigh]==-1){
                    bool res=bfs(neigh,graph);
                    if(res==false) return false;
                }
            }
        }
        return true;
    }
    
};