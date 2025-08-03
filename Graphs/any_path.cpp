#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>> graph;
int n;
unordered_set<int> visited; //to track the parent nodes

void add_edge(int source,int dest,bool direct=true){
       graph[source].push_back(dest);
       if(direct){
         graph[dest].push_back(source);
       }
}

bool dfs(int sorc,int dest){
       if(sorc==dest){  //if source becomes same as destination,we return true.
        return true;
       }
       visited.insert(sorc);  //because we r going to traverse its neighbours,so it is a parent for them now.
       for(auto neighbour:graph[sorc]){ //we are traversing all the neighbours of source who are not in visited set. 
        if(not visited.count(neighbour)){
            bool res=dfs(neighbour,dest);
            if(res){  //agar yeh true hua,means we got a path,hence we return true,we don't need to go ahead.
                return true;
            }
        }
       }
       visited.erase(sorc); //to erase the node whose neighbours we have explored
       return false;  //since we don't get any path from all the neighbours of this source,so we return false.
}
bool any_path(int source,int destination){
    return dfs(source,destination);
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
    int source,destination;
    cin>>source>>destination;
    cout<<any_path(source,destination);
    return 0;

}