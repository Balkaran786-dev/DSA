// #include<bits/stdc++.h>
// using namespace std;
// vector<list<int>> graph;  //graph

// int n;   //no. of vertices

// unordered_set<int> visited;  //to mark my visted nodes..

// void add_edge(int source,int dest){   
//     graph[source].push_back(dest); 
//     graph[dest].push_back(source);
// }

// void display(){
//     for(int i=0;i<graph.size();i++){
//         cout<<i<<" -> ";
//         for(auto el:graph[i]){
//             cout<<"("<<el<<")"<<",";
//         }
//         cout<<endl;
//     }
// }

// void dfs(int i){
     
//      visited.insert(i);
//      cout<<i<<" ";
//      for(auto neigh:graph[i]){
//         if(visited.count(neigh)==0){
//             dfs(neigh);
//         }
//      }
// }
// int main(){
//     cin>>n;
//     graph.resize(n); 
//     int e;
//     cin>>e;
//     while(e--){
//         int s,d;
//         cin>>s>>d;
//         add_edge(s,d);
//     }
//     display();
//     int components=0;
//     cout<<"\nThe depth first search of the above graph is:- "<<endl;
//     for(int i=0;i<graph.size();i++){
//           if(visited.count(i)==0){
//                components++;
//                dfs(i);
//           }
//     }

//     cout<<"\nThe number of components are:- "<<components;
//     return 0;
// }


