#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;   ///graph
int n;   //no. of vertices
unordered_set<int> vis;
void add_edge(int source,int dest){  
    graph[source].push_back(dest);
    graph[dest].push_back(source);
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
bool cycle_detect(){

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
    bool res=cycle_detect();
    cout<<res;
    return 0;
}