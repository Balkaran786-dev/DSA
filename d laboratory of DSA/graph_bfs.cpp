#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
int n;  //no. of vertices
unordered_set<int> visited; //to mark my visited nodes
queue<int> qu;    //to use it in my bfs
void add_edge(int source,int dest){
    graph[source].push_back(dest);
    graph[dest].push_back(source);
}
void display(){
    cout<<"\nOUR GRAPH:- \n";
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto ele:graph[i]){
            cout<<"("<<ele<<"),";
        }
        cout<<endl;
    }
}
void bfs(int i){
    qu.push(i);
    visited.insert(i);
    while(!qu.empty()){
        int node=qu.front();
        qu.pop();
        cout<<node<<" ";
        for(auto neigh:graph[node]){
            if(!visited.count(neigh)){
                qu.push(neigh);
                visited.insert(neigh);
            }
        }
    }
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
  int components=0;
  cout<<"\nThe breadth first search of the above graph is:- "<<endl;
  for(int i=0;i<n;i++){
    if(visited.count(i)==0){
        components++;
        bfs(i);
    }
  }

  cout<<"\n\nThe number of components are:- "<<components;
}

