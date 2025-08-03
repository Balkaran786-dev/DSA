#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
int n;
unordered_set<int> vis;
queue<int> qu; 
void add_edge(int source,int destination){
    graph[source].push_back(destination);
    graph[destination].push_back(source);
}
void bfs(int node){
    qu.push(node);
    while(!qu.empty()){
        int nodes_at_level=qu.size();
        while(nodes_at_level--){
            int curr_node=qu.front();
            vis.insert(curr_node);
            qu.pop();
            for(auto neigh:graph[curr_node]){
                if(not vis.count(neigh)){
                    qu.push(neigh);
                    vis.insert(neigh);
                }
            }
        }
    }
}
int connected_comp(){
    int count=0;
    //go to each node which are not in the visted list...
    //how many times you start dfs in graph ,that many cc are present...
    for(int i=0;i<n;i++){
        if(vis.count(i)==0){
            count++;
            bfs(i);
        }
    }
    return count;
}
int main(){
    cin>>n;
    graph.resize(n);
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    cout<<connected_comp();
    return 0;
}

