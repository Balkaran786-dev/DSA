#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<unordered_map<int,int>> graph;  //graph
int n;   //no. of vertices
void add_edge(int source,int dest,int wt=-1,bool is_bidirect=true){  
    graph[source][dest]=wt;  //graoh ke source(th) vector mein dest  ke coorresponding wt store krdo
    if(is_bidirect){
       graph[dest][source]=wt;
    }
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto el:graph[i]){
            cout<<"("<<el.first<<","<<el.second<<")"<<",";
        }
        cout<<endl;
    }
}
int main(){
    cin>>n;
    graph.resize(n);  //In this way,we resize a 2d array
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    display();
    int node1,node2;
    cin>>node1>>node2;
    if(graph[node1].find(node2)!=graph[node1].end()){
        cout<<"neighbour node";
    }
    else if(graph[node2].find(node1)!=graph[node2].end()){
        cout<<"neighbour node";
    }
    else{
        cout<<"not a neighbour node";
    }
    return 0;
}