#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
int n;
void add_edge(int sorc,int dest,bool bidirect=true){
    graph[sorc].push_back(dest);
    if(bidirect){
        graph[dest].push_back(sorc);
    }
}

void display(){
    for(int i=0;i<n;i++){
        cout<<i<<" -> ";
        for(auto neigh:graph[i]){
            cout<<neigh<<",";
        }
        cout<<endl;
    }
}

bool cycle_detect_bfs(){
    unordered_set<int> vis;
    queue<int> qu;
    vector<int> par(n,-1); //to check ki iff one neighbour is already visted,agr voh parent hua toh thek
                           // hai,varna there is a cycle
    qu.push(0); 
    vis.insert(0);
    while(!qu.empty()){
        int nodes_at_level=qu.size();
        while(nodes_at_level--){
            int node=qu.front();
            qu.pop();
            for(auto neigh:graph[node]){
                if(vis.count(neigh) && par[neigh]!=node) return true;
                if(!vis.count(neigh)){
                    qu.push(neigh);
                    vis.insert(neigh);
                    par[neigh]=node;
                }
            }
        }
    }
    return false;
}

int main(){
    cin>>n;
    graph.resize(n);
    int e;
    cin>>e;
    while(e--){
      int s,d;
      cin>>s>>d;
      add_edge(s,d,false);
    }
    display();
    bool ans=cycle_detect_bfs();
    if(ans==true) cout<<"Cycle detected";
    else cout<<"Cycle not detected";
    return 0;
}


