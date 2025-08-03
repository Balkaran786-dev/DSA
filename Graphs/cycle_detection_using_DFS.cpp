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
bool dfs(int source,int parent,unordered_set<int> &vis){
    vis.insert(source);
    
    for(auto neigh:graph[source]){
        if(vis.count(neigh) && neigh!=parent){
            return true;
        }
        if(not vis.count(neigh)){
            bool res=dfs(neigh,source,vis);
            if(res==true) return true;
        }
    }
    return false;
}
bool cycle_detect(){
    unordered_set<int> vis;
    for(int i=0;i<n;i++){  //esa esliye kar rhe hain taki koi bhi nodes shute na even agr disconnected graph hua toh bhi
       if(not vis.count(i)){
            bool res=dfs(i,-1,vis);
            if(res==true){
                return true;
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
      add_edge(s,d);
    }
    display();
    bool ans=cycle_detect();
    if(ans==true) cout<<"Cycle detected";
    else cout<<"Cycle not detected";
    return 0;
}