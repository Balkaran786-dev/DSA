//First, you need to find the diameter of each tree.

//Second, you need to find the maximum distance between any two nodes in the merged tree. This can be done by finding the maximum of the following three values:
//The diameter of the first tree.
//The diameter of the second tree.
//The height of tree1 + height of tree2 + 1.   height of tree = (diameter +1)/2;


class Solution {
public:
    int bfs(vector<vector<int>> &graph,int i,vector<int> &visit){
         int n=graph.size();
        queue<int> qu;
        int level=0;
        qu.push(i);
        visit[i]=level;
        
         while(!qu.empty()){
            level++;
            int sz=qu.size();
            while(sz--){
               int curr = qu.front(); qu.pop();
               for(auto neigh:graph[curr]){
                 if(visit[neigh]==-1){
                    qu.push(neigh);
                    visit[neigh]=level;
                 }
               }
            }
        }

        return level-1;
    }
    int TreeDiameter(vector<vector<int>> &graph){
        int n=graph.size();
        vector<int> visit(n,-1);
        int level=bfs(graph,0,visit);
        
        int node=-1;
        for(int i=0;i<n;i++){
            if(visit[i]==level){
                node=i;
            }
            visit[i]=-1;
        }
      
        return bfs(graph,node,visit);
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=1,m=1;
        for(int i=0;i<edges1.size();i++){
           n=max({edges1[i][0],edges1[i][1],n});
        }
        for(int i=0;i<edges2.size();i++){
           m=max({edges2[i][0],edges2[i][1],m});
        }
        vector<vector<int>> graph1(n+1),graph2(m+1);
        for(int i=0;i<edges1.size();i++){
            graph1[edges1[i][0]].push_back(edges1[i][1]);
            graph1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(int i=0;i<edges2.size();i++){
            graph2[edges2[i][0]].push_back(edges2[i][1]);
            graph2[edges2[i][1]].push_back(edges2[i][0]);
        }

        int dia1=TreeDiameter(graph1);
      
        int dia2=TreeDiameter(graph2);
       

        return max({1+((dia1+1)/2)+((dia2+1)/2),dia1,dia2});
    }
};