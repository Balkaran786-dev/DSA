#include<iostream>
#include<unordered_set>
#include<list>
#include<queue>
#include<vector>
using namespace std;
vector<list<int>> graph;
unordered_set<int> visited;
int n;
void add_edge(int source,int dest){
    graph[source].push_back(dest);
    graph[dest].push_back(source);
}
// vector<int> shortest_path(){
//     vector<int> min_path(n);
//     queue<int> qu;

//     if(graph.empty()){
//         return min_path;
//     }

//     int dist=0;
//     qu.push(0);
//     while(!qu.empty()){
//         int nodes_at_same_level=qu.size();
//         while(nodes_at_same_level--){
//            int curr=qu.front();
//            cout<<curr<<" ";
//            visited.insert(curr);
//            qu.pop();
//            min_path[curr]=dist;
//            for(auto ele:graph[curr]){
//               if(not visited.count(ele)){
//                 qu.push(ele);
//                 visited.insert(ele);
//               }
//            }
//         }
//         dist++;
//     }
//     cout<<endl;
//     return min_path;
// }
vector<int> shortest_path(){
    //in case of unweighted graph ,esme toh hum edges ke hisab se baat kr rhe hein

    vector<int> distance(n);
    queue<int> qu;
    qu.push(0);
    int dist=0;
    while(!qu.empty()){
        int nodes_at_same_level=qu.size();
        while(nodes_at_same_level--){
            int node=qu.front();
            qu.pop();
            visited.insert(node);
            distance[node]=dist;
            for(auto neigh:graph[node]){
                if(!visited.count(neigh)){
                    qu.push(neigh);
                    visited.insert(neigh);
                }
            }
        }
        dist++;
    }

    return distance;
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
    visited.clear();
    vector<int> ans=shortest_path();
    for(int i=0;i<ans.size();i++){
        cout<<i<<" -> "<<ans[i]<<" "<<endl;;
    }
    return 0;
}

