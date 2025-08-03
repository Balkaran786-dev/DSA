class Solution {
public:
    bool topo(vector<list<int>> &graph){
        vector<int> indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto neighbour:graph[i]){
                indegree[neighbour]++;
            }
        }
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
            for(auto neighbour:graph[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    qu.push(neighbour);
                    vis.insert(neighbour);
                }
            }
        }
        if(vis.size()==graph.size()) return true;
        else return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return topo(graph);
    }
};