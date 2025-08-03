//hum ek node pe jayenge fir uske sare neighbours pe jakar unhe
//visted mein dal denge,fir sath hi hum check kar rhe honge ki kya koi 
//node not visted toh nhi,agar haa,toh usse dfs start krenge and hum jitni 
//baar bhi yeh dfs start krenge utne hmare paas connected componenets honge.
#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>> graph;
int n;
unordered_set<int> visited;
queue<int> qu; 
void add_edge(int source,int destination){
    graph[source].push_back(destination);
    graph[destination].push_back(source);
}
void dfs(int node){
    visited.insert(node);
    for(auto neighbour:graph[node]){
        if(not visited.count(neighbour)){
            dfs(neighbour);
        }
    }
    //if we remove the curr node from our visted set,
    //we would finally not be able to get all those nodes
    //that we have traversed in the visited set.
}
int connected_comp(){
    int count=0;
    //go to each node which are not in the visted list...
    //how many times you start dfs in graph ,that many cc are present...
    for(int i=0;i<n;i++){
        if(visited.count(i)==0){
            count++;
            dfs(i);
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