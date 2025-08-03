class Graph {
public:
    vector<vector<int>> graph;
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);

        for(int i=0;i<n;i++){
            graph[i].resize(n,INT_MAX);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) graph[i][j]=0;
            }
        }
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]][edges[i][1]]=edges[i][2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX){
                        graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                    }
                }
            }
        }

    }
    
    void addEdge(vector<int> edge) {
        int n=graph.size();
        int k1=edge[0];
        int k2=edge[1];
        int wt=edge[2];
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
             if(graph[i][k1]!=INT_MAX && graph[k2][j]!=INT_MAX){
                graph[i][j]=min(graph[i][j],graph[i][k1]+wt+graph[k2][j]);
             }
           }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return (graph[node1][node2]==INT_MAX?-1:graph[node1][node2]);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */