#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph; 
int n;  //no. of vertices
void add_edge(int source,int dest,bool bidirectional=true){
    graph[source].push_back(dest);
    if(bidirectional){
        graph[dest].push_back(source);
    }
}
void topo(){
    vector<int> indegree(n,0); //to track the indegree of each node

    for(int i=0;i<n;i++){
        for(auto neigh:graph[i]){
           indegree[neigh]++; 
        }
    }
    
    queue<int> qu;
    unordered_set<int> st;

    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            qu.push(i);
            st.insert(i);
        }
    }

    while(!qu.empty()){
        int node=qu.front();
        qu.pop();
        cout<<node<<" ";
        for(auto neigh:graph[node]){
           if(!st.count(neigh)){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                qu.push(neigh);
                st.insert(neigh);            }
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
        add_edge(s,d,false);
    }
    topo();
    return 0;
}
//if you are not able to visit or print all the nodes that you have in your graph,
//that means topological sorting was not able to do the dependency resolution
//because the given graph was not a DAG.


// vector<int> indegree(n,0); //to track the indegree of each node

//     for(int i=0;i<n;i++){
//         for(auto neighbour:graph[i]){
//             indegree[neighbour]++;
//         }
//     }
//     queue<int> qu; //to store those nodes having zero indegree
//     unordered_set<int> vis; //to visit  only those that have zero degree.and jinko visit karliya unko dobara resolve krne ki jarurat nhi.
//     for(int i=0;i<n;i++){
//         if(indegree[i]==0){ 
//              qu.push(i);
//              vis.insert(i);
//         }
//     }

//     while(!qu.empty()){
//         int node=qu.front();
//         cout<<node<<" ";
//         qu.pop();
//         for(auto neigh:graph[node]){
//             if(not vis.count(neigh)){
//               indegree[neigh]--;
//               if(indegree[neigh]==0){//jinki indegree zero hoti jayegi,unko sath ke sath qu mein store krte jayenge.
//                 qu.push(neigh);
//                 vis.insert(neigh);
//               }
//             }
//         }
//     }